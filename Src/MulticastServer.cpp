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
    std::map<std::pair<std::string, std::string>, std::string> dst;
    size_t current_pos = 0;
    std::string encode; // string fro encryption which will be send by multicast
    std::stringstream ss;

    if( !key_value.empty() )
    {
        auto start = std::chrono::high_resolution_clock::now();

        while( current_pos < key_value.size() )
        {
            boost::archive::text_oarchive oa(ss);
            
            // iterators for insert from key_value
            auto first = std::next( std::make_move_iterator( key_value.begin() ), 
                                    current_pos 
                                  );
                                  
            auto last = std::next( std::make_move_iterator( key_value.begin() ), 
                                   current_pos+1'000 
                                 );

            dst.insert( std::make_move_iterator( first ), 
                        std::make_move_iterator( last )
                      );
        
        // Serialization
            oa << std::move( dst );

        // Encrypt
            AES->Encrypt( this->permanent_key,
                          this->permanent_iv, 
                          ss.str(), 
                          encode 
                        );
        // Send Multicast
            int send_count = sendto( send->sockfd,
                                     std::move( encode.data() ),
                                     encode.size(),
                                     0,
                                     (struct sockaddr*)&send->group,
                                     sizeof(send->group) 
                                   );

            current_pos += 1'000;            
            dst.clear();
            encode.clear();
            ss.clear();
        }
        auto stop = std::chrono::high_resolution_clock::now();

        // Send final message( means we will not send packages more now )
        int send_count = sendto( send->sockfd,
                                 "",
                                 sizeof(""),
                                 0,
                                 (struct sockaddr*)&send->group,
                                 sizeof(send->group) 
                               );
            
        std::chrono::duration< double, std::milli > fp_ms = stop - start;
        std::cout << "while end: " << fp_ms.count() << std::endl;
        std::cin.get();
    
    }
        

/*
        std::stringstream ss;
        boost::archive::text_oarchive oa(ss);
        oa << key_value; 

        size_t start_pos = 0;
        
        while( start_pos < ss.str().size() )
        {
            std::string encod;

            // Encrypt string with length of 512 bytes
            AES->Encrypt( this->permanent_key, 
                          this->permanent_iv, 
                          ss.str().substr( start_pos, 512 ), 
                          encod 
                        );

            // send encrypted string( size may be bigger than 512 ) by multicast
            int send_count = sendto( send->sockfd,
                                     encod.data(),
                                     encod.size(),
                                     0,
                                     (struct sockaddr*)&send->group,
                                     sizeof(send->group) 
                                   );
            
            // init new position for new iteration
            start_pos += 512;
        }
        std::cout << ss.str().size() << " : " << start_pos << std::endl;
        //std::cout << "while end" << std::endl;
        //std::cin.get();
*/
/*
        AES->Encrypt( this->permanent_key, this->permanent_iv, ss.str(), encod );
        int len = encod.size() + (encod.size() % 128);

        ssize_t send_count; // how much data send
        char* p = encod.data();


        sendto( send->sockfd, &len, sizeof(len), 0, 
                (struct sockaddr*)&send->group,
                sizeof(send->group)
              );
        std::cout << len << std::endl;
            

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
*/

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