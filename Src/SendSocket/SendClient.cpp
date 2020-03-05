#include "../../Include/SendSocket/SendClient.h"

#include "../../Include/CryptoAssymetric/CryptoAssymetric.h"
#include "../../Include/CryptoAssymetric/RSA.h"

#include "../../Include/CryptoHash/HashSHA3_256.h"

#include "../../Include/CryptoSymmetric/CryptoSymmetric.h"
#include "../../Include/CryptoSymmetric/AesModeCBC.h"


SendClient::SendClient( const std::string s_addr_,
                        const short port_ )
                      : SendSocket(s_addr_, port_)
{
}

SendClient::~SendClient()
{
}

void SendClient::CreateSocket()
{
    try
    {
        socketfd = socket( AF_INET, SOCK_STREAM, 0 );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void SendClient::InitSocket()
{
    try
    {
        bzero( &sockaddr, sizeof(sockaddr) );
        sockaddr.sin_family = AF_INET;
        sockaddr.sin_port = htons(port);
        sockaddr.sin_addr.s_addr = inet_addr( s_addr.c_str() );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void SendClient::Connect()
{
    try
    {
        int check = 0;
        if( ( check = connect( socketfd, 
                               (struct sockaddr*)&sockaddr, 
                               sizeof(sockaddr) 
                             ) 
            ) < 0
          )
          throw std::runtime_error(" Connect() SendClient Error \n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void SendClient::Authentification(  AesModeCBC* AES,
                                    HashSHA3* sha,
                                    std::vector<byte>& permanent_key,
                                    std::vector<byte>& permanent_iv,
                                    std::vector<byte>& AES_Ticket
                                 )
{
// Load Bob Public Key from file( me must trust this key )
    RSA Bob(2048);
    Bob.LoadPublicKeyFromFile("server_pubkey.dat");
// End Load Bob Public Key from file( me must trust this key )
    
// Generate RSA key pair for new connection to server
    RSA Alice(3072);
    Alice.Key_generation();
// End Generate RSA key pair for new connection to server

// Send Alice Login Encrypted By Bob Public Key
    std::string Alice_login; // Alice_login ciphertext is encoded in Hex
    Bob.Encrypt("Alice", Alice_login);
    int n = 0;

    n = write( socketfd, Alice_login.data(), Alice_login.size() );
// End Send Alice Login Encrypted By Bob Key

// Send Alice public_key To Bob
    std::string Alice_public_key; // Key is encoded in Base64
    Alice.SavingPublicKeyToString(Alice_public_key);

    sleep(1);

    n = write( socketfd, Alice_public_key.data(), Alice_public_key.size() );
// END Send Alice public_key To Bob

// Receive Encrypted by Alice public and Signed by Bob private Key from Bob
    sleep(1);

    std::string recv_message;
    recv_message.resize(768);

    n = read ( socketfd, &recv_message[0], 768 );
    //std::cout << "Recv_message AES_KEY: " << recv_message.data() << std::endl;
    std::vector<byte> AES_KEY(Bob.Verify( Alice.Decrypt(recv_message) ) );
// End Receive Encrypted by Alice public and Signed by Bob private Key from Bob

// Receive Encrypted Signed IV by private key from Bob
    sleep(1);

    n = read ( socketfd, &recv_message[0], 768 );
    std::vector<byte>AES_IV(Bob.Verify( Alice.Decrypt(recv_message) ) );
// End Receive Encrypted Signed IV by private key from Bob

// Receive Encrypted Signed Ticket by private key from Bob
    sleep(1);

    n = read ( socketfd, &recv_message[0], 768 );
    AES_Ticket = (Bob.Verify( Alice.Decrypt(recv_message) ) );
    //std::cout << "Ticket: " << AES_Ticket.data() << std::endl << AES_Ticket.size() << std::endl;
// End Receive Encrypted Signed Ticket by private key from Bob

// Calculate Digest: SHA3_256( AES_Ticket + password );
    std::string digest;

    sha->AddDataToSHA3object(std::string{AES_Ticket.begin(), AES_Ticket.end()}+"I am Client");
    sha->SetDigestStringSHAsize(digest);
    sha->CalculateDigest(digest);
// End Calculate Digest: SHA3_256( AES_Ticket + password );

// Encrypt Hash3_256 by Ephemere Key Received from Bob and Send it to him
    std::string aes_cipher;
    //AesModeCBC AES(CryptoPP::AES::DEFAULT_KEYLENGTH, CryptoPP::AES::BLOCKSIZE);
    AES->Encrypt( AES_KEY, AES_IV, digest, aes_cipher );

    sleep(1);

    n = write( socketfd, aes_cipher.data(), aes_cipher.size() );
// End Encrypt Hash3_256 by Ephemere Key Received from Bob

// Receive AES Permanent Key form Bob
    sleep(1);

    recv_message.resize(32);
    read( socketfd, &recv_message[0], 32 );

    AES->Decrypt( AES_KEY, AES_IV, recv_message, permanent_key );

    std::cout << "AES_KEY: ";
    std::cout << permanent_key.data() << std::endl;
// END Receive AES Permanent Key form Bob

// Receive AES Permanent IV from Bob
    recv_message.resize(32);
    read( socketfd, &recv_message[0], 32 );

    AES->Decrypt( AES_KEY, AES_IV, recv_message, permanent_iv );

    std::cout << "AES_IV: ";
    std::cout << permanent_iv.data();
    std::cout << std::endl;
// End Receive AES Permanent IV from Bob


}