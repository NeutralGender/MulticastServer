#ifndef _DRIVER
#define _DRIVER

#include <array>
#include <map>

// Abstract Class for DBs
class DBDriver
{
public:
    virtual ~DBDriver() = 0;

    virtual void Connect() = 0;
    virtual void Read() = 0;
    virtual void GetAllData(std::map<std::pair<std::string,std::string>,
                            std::string>&) = 0;
    virtual void PipelineWrite(std::map<std::pair<std::string,std::string>,
                               std::string>&) = 0;
    virtual void Authentication(std::string_view key) = 0;
    virtual void Write(std::array<char,512>) = 0; 
};

#endif