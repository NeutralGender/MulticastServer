#include <iostream>

#include "Include/MulticastServer.h"
#include "Include/SocketMulticast/ReceiveSocketMulticast.h"
#include "Include/SocketMulticast/SendSocketMulticast.h"
#include "Include/DBDriver/RedisDriver.h"

#include "Include/SendSocket/SendClient.h"
#include "Include/CryptoSymmetric/AesModeCBC.h"
#include "Include/CryptoHash/HashSHA3_256.h"


int main()
{

    // Symmetric CryptoSystem
    AesModeCBC AES( 16, 16 );
    // Hash
    HashSHA3 sha3;

    SendClient sc( "192.168.56.106", 8000 );
    sc.CreateSocket();
    sc.InitSocket();
    sc.Connect();

    MulticastServer m;
    m.Authentification( &sc, &AES, &sha3 );

    RedisDriver redis("127.0.0.1", 6379);
    //RedisDriver redis("192.168.107.42", 6383);

    // SendSocket send( "local", "group", port );
    SendSocketMulticast send( "192.168.56.112", "225.1.1.1", 8000 );
    send.Create_Socket();
    send.SetSockLoop();
    send.SetOutInterface();
    
    m.ConnectToDb(&redis);

    while(true)
    {
        m.GetAllData(&redis);
        //std::cout << "cin.get(): Press button" << std::endl;
        //std::cin.get();
        m.SendMsg( &send, &AES );
    }

    return 0;
}
