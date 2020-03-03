#ifndef _SEND_CLIENT
#define _SEND_CLIENT

#include "SendSocket.h"

//#include "../CryptoSymmetric/AesModeCBC.h"

#include <vector>

class SendClient : SendSocket
{
private:
    
public:
    SendClient( const std::string s_addr_,
                const short port_);
    ~SendClient();

    virtual void CreateSocket() override;
    virtual void InitSocket() override;
    virtual void Connect() override;
    //virtual void Authentification() override;
    virtual void Authentification( AesModeCBC* AES,
                                   HashSHA3* sha,
                                   std::vector<byte>& permanent_key,
                                   std::vector<byte>& AES_IV,
                                   std::vector<byte>& AES_Ticket
                                 ) override;

};

#endif