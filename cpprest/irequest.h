#ifndef CPPREST_IREQUEST_H
#define CPPREST_IREQUEST_H

#include <string>
#include <map>
#include <string.h>
#include <memory_buffer.h>

namespace cpprest{

typedef std::map<std::string, std::string> MT_HttpHeaders;

class IRequest
{
public:
    std::string path_;
    MT_HttpHeaders headers_;
    kw::MemoryBuffer content_;
};

}
#endif // IREQUEST_H
