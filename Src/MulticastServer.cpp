#include "../Include/MulticastServer.h"

MulticastServer::MulticastServer()
{

}

MulticastServer::~MulticastServer()
{

}

void MulticastServer::ReceiveMsg(ReceiveSocketMulticast* receive)
{
   try
    {
        int valid = 0;
        std::string str = "";
        if( ( valid = read( receive->sockfd, arr.data(), arr.size() ) ) < 0 )
            throw std::runtime_error("Cannot Read Socket");

        std::cout << "ValidR: " << valid << std::endl;
        std::cout << "Received:" << arr.data() << std::endl;
    }
    catch(const std::runtime_error& r)
    {
        std::cerr << r.what() << ": " << errno << '\n';
    }
}

void MulticastServer::SendMsg(SendSocketMulticast* send,
                              AesModeCBC* AES)
{
    std::cout << "SendMSG " << std::endl;
    // SERIALIZATION
    std::stringstream ss;
    boost::archive::text_oarchive oa(ss);
    oa << key_value; 

    std::string encod;//, decod;

    AES->Encrypt( this->permanent_key, this->permanent_iv, ss.str(), encod );
    int len = encod.size();// + (encod.size() % 128);
    ssize_t send_count; // how much data send
    char* p = encod.data();

    sendto( send->sockfd, &len, sizeof(len), 0, 
            (struct sockaddr*)&send->group,
            sizeof(send->group)
          );

    while( len > 0 && ( send_count = sendto( send->sockfd,
                                             p,
                                             512,
                                             0,
                                             (struct sockaddr*)&send->group,
                                             sizeof(send->group) 
                                           ) 
                      ) > 0
         )
    {
        p += send_count; // pointer to current byte plus how much bytes we send now;
        len -= (size_t)send_count; // update sizeof message we must send
    }
    std::cout << "Size: " << encod.size() << std::endl;
    std::cout << "Len: " << len << std::endl;

}

void MulticastServer::WriteToDB(DBDriver *db_driver)
{
    db_driver->Write(arr);
}

void MulticastServer::ConnectToDb(DBDriver *db_driver)
{
    db_driver->Connect();
}

void MulticastServer::Authentication(DBDriver *db_driver, 
                                     std::string_view key)
{
    db_driver->Authentication(key);
}

void MulticastServer::ReadFromDB(DBDriver *db_driver)
{
    db_driver->Read();
}

void MulticastServer::GetAllData(DBDriver *db_driver)
{
    db_driver->GetAllData(key_value);
}

void MulticastServer::PipelineWrite(DBDriver *db_driver)
{
    db_driver->PipelineWrite(key_value);
}

void MulticastServer::Authentification( SendClient* sendClient,
                                        AesModeCBC* AES,
                                        HashSHA3* sha
                                      )
{
    sendClient->Authentification( AES, sha, permanent_key, permanent_iv, AES_Ticket );
}