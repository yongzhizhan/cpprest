#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <thread.h>
#include "zshare_def.h"

namespace cpprest{

class HttpClient
{
public:
    HttpClient();
    ~HttpClient();

    Response Send(const Request& request, int timeout_ms);

private:
    void EventLoop();

private:
    //
};

}
#endif // HTTPCLIENT_H
