#ifndef CPPREST_RESPONSE_H
#define CPPREST_RESPONSE_H

#include <string>
#include <map>
#include <memory_buffer.h>
#include "zshare_def.h"

namespace cpprest{

class Response
{
public:
    Response():code_ (200){}

    int code_;
    HttpHeaders headers_;
    kw::MemoryBuffer content_;
};

}
#endif // CPPREST_IRESPONSE_H
