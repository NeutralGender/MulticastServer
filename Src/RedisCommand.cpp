#include "../Include/RedisCommand.h"
#include "../Include/RedisConnection.h" // Must be included, because of incomplete class
                                        // (class in another file)

RedisCommand::RedisCommand()
{

}

RedisCommand::~RedisCommand()
{
    freeReplyObject(reply);
}

void RedisCommand::PipelineWrite(RedisConnection* rconnection,
                                 std::map<std::pair<std::string,std::string>,std::string>& key_value)
{
    // REDIS_OK = 0;
    // REDIS_ERR = -1;
    int appednState = -1;
    std::cout << "Pipe:" << key_value.size() << std::endl;

    for(auto it = key_value.cbegin(); it != key_value.cend(); it++ )
    {
        std::cout << it->first.first << std::endl;
        std::cout << (size_t) sizeof (it->first.first.c_str()) << ":" << it->first.first.c_str() << ";" 
                  << (size_t) sizeof (it->first.second.data()) << ":" << it->first.second.data() << ";"
                  << (size_t) sizeof (it->second.data())       << ":" << it->second.data()       << std::endl;

        reply = static_cast<redisReply*>(redisCommand(rconnection->rconnect,
                                                      "HSET %b %b %b",
                                                      it->first.first.c_str(),  
                                                        (size_t) strlen (it->first.first.data()),
                                                      it->first.second.data(), 
                                                        (size_t) sizeof (it->first.second.data()),
                                                      it->second.data(),       
                                                        (size_t) sizeof (it->second.data())
                                                     )
                                        );
    }

}

void RedisCommand::Write(RedisConnection* rconnection, 
                     std::array<char ,512> arr)
{
    try
    {
        reply = static_cast<redisReply*>(redisCommand(rconnection->rconnect,
                                                      arr.data()
                                                     )
                                        );
        
        std::cout << reply->str << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

void RedisCommand::Read(RedisConnection* rconnection, 
                        std::string_view key)
{
    try
    {
        reply = static_cast<redisReply*>(redisCommand(rconnection->rconnect,
                                                      "GET key0",
                                                      key.data()
                                                     )
                                        );
        std::cout << "ReadData: " << reply->str << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}

void RedisCommand::Authentication(RedisConnection* rconnection,
                                  std::string_view key)
{
    try
    {
        //BarbaDDoSoperat10n
        reply = static_cast<redisReply*>(redisCommand(rconnection->rconnect,
                                                      "AUTH %s",
                                                      key.data()
                                                     )
                                        );
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void RedisCommand::GetAllData(RedisConnection* rconnection,
                              std::map<std::pair<std::string,std::string>,std::string>& key_value)
{

    key_value.clear();
    try
    {
        reply = static_cast<redisReply*>(redisCommand(rconnection->rconnect,
                                                      "KEYS *"));
        redisReply *temp;
        for( size_t i = 0; i < reply->elements; i++ )
        {
            temp = static_cast<redisReply*>(redisCommand(rconnection->rconnect,
                                                         "HGETALL %b", &reply->element[i]->str[0],//8)
                                                         (size_t) strlen(reply->element[i]->str))
                                           );

            for(size_t j = 0; j < temp->elements; j = j+2)
            {
                key_value.try_emplace(std::make_pair(std::string(reply->element[i]->str), 

                                                     std::string{temp->element[j]->str,
                                                                 strlen(temp->element[j]->str) } ), 
                                                                 //sizeof(temp->element[j]->str) } ),

                                                     std::string{temp->element[j+1]->str,
                                                                 strlen(temp->element[j+1]->str) }
                                                                 //sizeof(temp->element[j+1]->str) }
                                     );
            }
            freeReplyObject(temp);
        }

/*
        for( auto it = key_value.cbegin(); it != key_value.cend(); it++ )
            std::cout << it->first.first << " - "
                      << it->first.second << " : "
                      << it->second.data()
                      << std::endl;
        std::cin.get();
*/

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}