#ifndef CPPREST_REQUEST_H
#define CPPREST_REQUEST_H

#include <evhttp.h>
#include <string>
#include <map>
#include <string.h>
#include <memory_buffer.h>
#include "zshare_def.h"
#include <string_arg.h>

namespace cpprest{

class Request
{
public:
    Request(evhttp_request* req_handler);
    ~Request();

    const char* Path();

    Method ReqMethod();

    std::string Header(kw::StringArg key, int len);

    kw::shared_ptr<kw::MemoryBuffer> Content();

    const char* GetParamS(const char* name, const char* def);
    int GetParamI(const char* name, int def);

private:
    evhttp_request* req_handler_;
    struct evkeyvalq params_;
    kw::shared_ptr<kw::MemoryBuffer> content_;
};

}
#endif // IREQUEST_H
