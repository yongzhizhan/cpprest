#ifndef CPPREST_IRESPONSE_H
#define CPPREST_IRESPONSE_H

#include <string>
#include <memory_buffer.h>

namespace cpprest{

typedef std::map<std::string, std::string> MT_HttpHeaders;

class IResponse
{
public:
    MT_HttpHeaders headers_;
    int code_;
    kw::MemoryBuffer content_;
};

}
#endif // CPPREST_IRESPONSE_H
