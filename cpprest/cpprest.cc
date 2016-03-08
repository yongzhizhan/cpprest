#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpprest.h"

namespace cpprest
{

CppRest::CppRest(kw::StringArg host, unsigned short port, int thread_count, const RouteItems &route_items)
    :http_server_(new HttpServer(host.data(), port)), router_(new Router(route_items, thread_count))
{
    recv_slot_ = http_server_->recv_signal_.Connect(std::tr1::bind(&Router::OnRecv, router_, std::tr1::placeholders::_1, std::tr1::placeholders::_2));
    reply_slot_ = router_->reply_signal_.Connect(std::tr1::bind(&HttpServer::Reply, http_server_, std::tr1::placeholders::_1, std::tr1::placeholders::_2));
}

CppRest::~CppRest()
{
}

bool CppRest::Start()
{
    return http_server_->Start();
}

bool CppRest::Stop()
{
    return http_server_->Stop();
}

void CppRest::Join()
{
    return http_server_->Join();
}

}
