#ifndef CPPREST_H
#define CPPREST_H

#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <mutex.h>
#include <Singleton.h>
#include <http_server.h>
#include <string_arg.h>
#include <map>
#include "zshare_def.h"
#include "request.h"
#include "response.h"
#include "router.h"

namespace cpprest
{

class CppRest
{
public:
    typedef std::tr1::shared_ptr<cpprest::Router> RouterPtr;
    typedef std::tr1::shared_ptr<cpprest::HttpServer> HttpServerPtr;

    CppRest(kw::StringArg host, unsigned short port, int thread_count, const RouteItems& route_items);
    ~CppRest();

    bool Start();
    bool Stop();
    void Join();

    HttpServerPtr Server(){return http_server_;}

private:
    RouterPtr router_;
    HttpServerPtr http_server_;

    kw::SlotHandle recv_slot_;
    kw::SlotHandle reply_slot_;
};

}

#endif // CPPREST_H
