#ifndef _MulticastServer
#define _MulticastServer

typedef unsigned char byte;

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include <string.h>
#include <map>
#include <array>
#include <vector>
#include <chrono>

#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
//#include <boost/serialization/binary_object.hpp>

//#include <boost/archive/binary_iarchive.hpp>
//#include <boost/archive/binary_oarchive.hpp>

#include "DBDriver/DBDriver.h"
#include "SendSocket/SendClient.h"
#include "CryptoSymmetric/AesModeCBC.h"
#include "CryptoHash/HashSHA3_256.h"
#include "SocketMulticast/ReceiveSocketMulticast.h"
#include "SocketMulticast/SendSocketMulticast.h"

class MulticastServer
{
private:
    std::array<char,512> arr;
    std::vector<byte> permanent_key;
    std::vector<byte> permanent_iv;
    std::vector<byte> AES_Ticket;
    std::map<std::pair<std::string,std::string>,std::string> key_value;
public:
    MulticastServer();
    ~MulticastServer();

    void ReceiveMsg(ReceiveSocketMulticast* receive);
    void SendMsg(SendSocketMulticast* send,
                 AesModeCBC* AES);

    void Authentification( SendClient* sendClient,
                           AesModeCBC* AES,
                           HashSHA3* sha
                         );

    void ConnectToDb(DBDriver *db_driver);
    void Authentication(DBDriver *db_driver, std::string_view key);
    void WriteToDB(DBDriver *db_driver);
    void GetAllData(DBDriver *db_driver);
    void PipelineWrite(DBDriver *db_driver);
    void ReadFromDB(DBDriver *db_driver);
};




#endif