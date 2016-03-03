#ifndef CPPREST_REQUEST_H
#define CPPREST_REQUEST_H

#include <string>
#include <map>
#include <string.h>
#include <memory_buffer.h>
#include "zshare_def.h"

namespace cpprest{

class Request
{
public:
    std::string path_;
    Method method;
    HttpHeaders headers_;
    kw::MemoryBuffer content_;
};

}
#endif // IREQUEST_H
