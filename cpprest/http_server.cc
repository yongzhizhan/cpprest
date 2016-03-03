#include <stdlib.h>
#include "http_server.h"
#include <evhttp.h>

namespace cpprest
{

HttpServer::HttpServer(const char* listen_addr, unsigned short listen_port)
    :listen_addr_(listen_addr), listen_port_(listen_port),
      thread_loop_(std::tr1::bind(&HttpServer::EventLoop,  this), "eventloop")
{
    evbase_ = event_base_new();
    if(0 == evbase_)
    {
        fprintf(stderr, "Couldn't create an event_base:exiting\n");
        exit(1);
    }

    evhttp_ = evhttp_new(evbase_);
    if(0 == evhttp_)
    {
        fprintf(stderr, "Couldn't create an evhttp:exiting\n");
        exit(1);
    }

    evhttp_set_gencb(evhttp_, &HttpServer::Request_Callback, this);

    evhandle = evhttp_bind_socket_with_handle(evhttp_, listen_addr_.c_str(), listen_port_);
    if(0 == evhandle)
    {
        fprintf(stderr, "Couldn't bind %s:%d:exiting\n", listen_addr_.c_str(), listen_port);
        exit(1);
    }

    break_loop_ = false;

    evtimer_ = evtimer_new(evbase_, &HttpServer::EventTimer, this);

    timeval one_sec = {1, 0};
    evtimer_add(evtimer_, &one_sec);

    thread_loop_.Start();
}

HttpServer::~HttpServer()
{
    Stop();
    thread_loop_.Join();

    if(0 != evbase_)
        event_base_free(evbase_);

    if(0 != evhttp_)
        evhttp_free(evhttp_);
}

bool HttpServer::Start()
{
    if(thread_loop_.Started())
        return true;

    return thread_loop_.Start();
}

bool HttpServer::Stop()
{
    break_loop_ = true;
    thread_loop_.Join();

    return true;
}

void HttpServer::Join()
{
    thread_loop_.Join();
}

void HttpServer::EventLoop()
{
    event_base_dispatch(evbase_);
}

void  HttpServer::EventTimer(evutil_socket_t fd, short flag, void* arg)
{
    HttpServer* http_server = (HttpServer*)arg;
    if(false == http_server->break_loop_)
    {
        evtimer_del(http_server->evtimer_);

        timeval one_sec = {1, 0};
        evtimer_add(http_server->evtimer_, &one_sec);
        return;
    }

    event_base_loopbreak(http_server->evbase_);
}

void HttpServer::Request_Callback(evhttp_request* request, void* arg)
{
    //http_server life longger than this function
    HttpServer* http_server = static_cast<HttpServer*>(arg);

    kw::shared_ptr<Request> req(new Request(request));

    http_server->recv_signal_.Emit((void*)request, req);
}

void HttpServer::Reply(void* req_handle, kw::shared_ptr<Response> &response)
{
    evhttp_request* request = static_cast<evhttp_request*>(req_handle);
    evkeyvalq* headers = evhttp_request_get_output_headers(request);

    for(cpprest::HttpHeaders::const_iterator iter = response->headers_.begin();
        response->headers_.end() != iter; ++iter)
    {
        evhttp_add_header(headers, iter->first.c_str(), iter->second.c_str());
    }

    evbuffer* buf = evbuffer_new();
    evbuffer_add(buf, response->content_.Data(), response->content_.Length());

    evhttp_send_reply(static_cast<evhttp_request*>(req_handle), response->code_, "", buf);
    evbuffer_free(buf);
}

}

