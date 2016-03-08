#include <stdlib.h>
#include "http_server.h"
#include <evhttp.h>
#include <thread_info.h>

namespace cpprest
{

HttpServer::HttpServer(const char* listen_addr, unsigned short listen_port)
    :listen_addr_(listen_addr), listen_port_(listen_port),
     thread_loop_(std::tr1::bind(&HttpServer::EventLoop,  this), "eventloop")
{
    break_loop_ = false;

    //add socket pair
    int sockets[2];
    if(0 != socketpair(AF_UNIX,  SOCK_STREAM, 0, sockets))
    {
        fprintf(stderr, "socketpair failed\n");
        exit(1);
    }

    socket_read_ = sockets[0];
    socket_write_ = sockets[1];
}

HttpServer::~HttpServer()
{
    Stop();

    close(socket_read_);
    close(socket_write_);
}

bool HttpServer::Start()
{
    if(thread_loop_.Started())
        return true;

    return thread_loop_.Start();
}

bool HttpServer::Stop()
{
    if(false == thread_loop_.Started())
        return true;

    break_loop_ = true;
    if(0 > write(socket_write_, "z", 1))
    {
        fprintf(stderr, "write socket failed\n");
        exit(1);
    }

    thread_loop_.Join();

    return true;
}

void HttpServer::Join()
{
    thread_loop_.Join();
}

void HttpServer::EventLoop()
{
    thread_loop_tid_ = kw::thread_info::ThreadId();

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

    evhttp_set_gencb(evhttp_, &HttpServer::RequestCB, this);

    evhandle = evhttp_bind_socket_with_handle(evhttp_, listen_addr_.c_str(), listen_port_);
    if(0 == evhandle)
    {
        fprintf(stderr, "Couldn't bind %s:%d:exiting\n", listen_addr_.c_str(), listen_port_);
        exit(1);
    }

    evread_ = event_new(evbase_, socket_read_, EV_PERSIST | EV_READ, &HttpServer::OnRead, this);
    if(0 != event_add(evread_, 0))
    {
        fprintf(stderr, "event add failed\n");
        exit(1);
    }

    event_base_dispatch(evbase_);

    event_del(evread_);

    event_free(evread_);
    evhttp_free(evhttp_);

    event_base_free(evbase_);

}

void HttpServer::RequestCB(evhttp_request* request, void* arg)
{
    //http_server life longger than this function
    HttpServer* http_server = static_cast<HttpServer*>(arg);
    kw::shared_ptr<Request> req(new Request(request));

    evhttp_connection_set_closecb(request->evcon, &HttpServer::CloseCB, arg);

    printf("request, handle:%p.....\n", request);

    http_server->recv_signal_.Emit((void*)request, req);
}

void HttpServer::CloseCB(evhttp_connection* conn, void* arg)
{
    HttpServer* http_server = static_cast<HttpServer*>(arg);
    http_server->close_signal_.Emit(conn);
}

void HttpServer::OnRead(int socket, short flag, void *arg)
{
    //run in evbase thread
    HttpServer* http_server = static_cast<HttpServer*>(arg);
    assert(http_server->thread_loop_tid_ == kw::thread_info::ThreadId());

    char buf[1];
    int read_size;
    EventTask task;

    {
        kw::MutexGuard gurad(http_server->mutex_);
        std::queue<EventTask>& event_task = http_server->event_task_;

        if(true == event_task.empty())
        {
            //read
            read_size = read(http_server->socket_read_, buf, sizeof buf);
            if(0 > read_size)
            {
                fprintf(stderr, "wait to read socket failed.\n");
                exit(-1);
            }
        }

        if(true == event_task.empty())
            return;

        task = event_task.front();
        event_task.pop();
    }

    task();
}

void HttpServer::Reply(void* req_handle, kw::shared_ptr<Response> &response)
{
    {
        kw::MutexGuard gurad(mutex_);
        EventTask task = std::tr1::bind(&HttpServer::Reply_, this, req_handle, response);
        event_task_.push(task);
    }

    write(socket_write_, "z", 1);

}

void HttpServer::Reply_(void* req_handle, kw::shared_ptr<Response> &response)
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

    //printf("reply, handle:%p, code:%d,Content:%s.....\n", req_handle, response->code_, response->content_.Data());
    //evhttp_send_reply(static_cast<evhttp_request*>(req_handle), response->code_, "", buf);
    evhttp_send_reply(static_cast<evhttp_request*>(req_handle), response->code_, "", buf);
    evbuffer_free(buf);
}

}


