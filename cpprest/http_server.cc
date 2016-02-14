#include <stdlib.h>
#include "http_server.h"
#include <evhttp.h>

namespace cpprest
{

HttpServer::HttpServer(const char* listen_addr, unsigned short listen_port)
    :listen_addr_(listen_addr), listen_port_(listen_port),
      thread_loop_(std::tr1::bind(&HttpServer::EventLoop,  this), "eventloop"),
      recv_callback_(0)
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
    event_base_loopbreak(evbase_);
    thread_loop_.Join();

    return true;
}

void HttpServer::Request_Callback(evhttp_request* request, void* arg)
{
    const char* cmdtype;
    switch (evhttp_request_get_command(request)) {
    case EVHTTP_REQ_GET: cmdtype = "GET"; break;
    case EVHTTP_REQ_POST: cmdtype = "POST"; break;
    case EVHTTP_REQ_HEAD: cmdtype = "HEAD"; break;
    case EVHTTP_REQ_PUT: cmdtype = "PUT"; break;
    case EVHTTP_REQ_DELETE: cmdtype = "DELETE"; break;
    case EVHTTP_REQ_OPTIONS: cmdtype = "OPTIONS"; break;
    case EVHTTP_REQ_TRACE: cmdtype = "TRACE"; break;
    case EVHTTP_REQ_CONNECT: cmdtype = "CONNECT"; break;
    case EVHTTP_REQ_PATCH: cmdtype = "PATCH"; break;
    default: cmdtype = "unknown"; break;
    }

    printf("Received a %s request for %s\n", cmdtype, evhttp_request_get_uri(request));

    HttpServer* http_server = static_cast<HttpServer*>(arg);
    if(0 == http_server->recv_callback_)
    {
        printf("unset recv_callback_ use default.\n");

        IResponse response;
        response.code_ = 200;

        http_server->Reply(request, response);
        return;
    }

    IRequest req;
    req.path_ = evhttp_request_get_uri(request);

    evkeyvalq* headers = evhttp_request_get_input_headers(request);
    for(evkeyval* header = headers->tqh_first; header; header = header->next.tqe_next)
        req.headers_[header->key] = header->value;

    evbuffer* input_buf = evhttp_request_get_input_buffer(request);
    while (evbuffer_get_length(input_buf))
    {
        char cbuf[128];
        int count = evbuffer_remove(input_buf, cbuf, sizeof(cbuf));
        if (count <= 0)
            continue;

        req.content_.Append(cbuf, count);
    }

    http_server->recv_callback_((void*)request, req);
}

void HttpServer::EventLoop()
{
    event_base_dispatch(evbase_);
}

void HttpServer::Reply(void* req_handle, IResponse &response)
{
    evhttp_request* request = static_cast<evhttp_request*>(req_handle);
    evkeyvalq* headers = evhttp_request_get_output_headers(request);
    for(cpprest::MT_HttpHeaders::const_iterator iter = response.headers_.begin();
        response.headers_.end() != iter; ++iter)
    {
        evhttp_add_header(headers, iter->first.c_str(), iter->second.c_str());
    }

    printf("response data:%s", response.content_.Data());
    evbuffer* buf = evbuffer_new();
    evbuffer_add(buf, response.content_.Data(), response.content_.Length());

    evhttp_send_reply(static_cast<evhttp_request*>(req_handle), response.code_, "", buf);
    evbuffer_free(buf);
}

}

