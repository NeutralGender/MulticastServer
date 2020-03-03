#ifndef _SENDSOCKET
#define _SENDSOCKET

typedef unsigned char byte;

#include <iostream>
#include <vector>
#include <exception>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../CryptoSymmetric/AesModeCBC.h"
#include "../CryptoHash/HashSHA3_256.h"

class SendSocket
{
protected:
    int socketfd = 0;
    const std::string s_addr;
    const short port;
    struct sockaddr_in sockaddr;
public:
    SendSocket( const std::string s_addr_,
                const short port_ );
    virtual ~SendSocket() = 0;

    virtual void CreateSocket() = 0;
    virtual void InitSocket() = 0;
    virtual void Connect() = 0;
    virtual void Authentification( AesModeCBC* AES,
                                   HashSHA3* sha,
                                   std::vector<byte>& permanent_key,
                                   std::vector<byte>& AES_IV,
                                   std::vector<byte>& AES_Ticket
                                 ) = 0;

};

#endif