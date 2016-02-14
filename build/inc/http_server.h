#ifndef CPPREST_HTTPSERVER_H
#define CPPREST_HTTPSERVER_H

#include <boost/noncopyable.hpp>
#include <tr1/memory>
#include <tr1/functional>
#include <string>
#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <thread.h>
#include "irequest.h"
#include "iresponse.h"

namespace cpprest
{

class HttpServer : public boost::noncopyable
{
public:
    typedef std::tr1::function<void(void*, IRequest&)> RecvCallback;

public:
    HttpServer(const char* listen_addr, unsigned short listen_port);
    ~HttpServer();

    bool Start();
    bool Stop();

    void SetRecvCallback(RecvCallback recv_callback)
    {
        recv_callback_ = recv_callback;
    }

    void Reply(void* req_handle, IResponse &response);

private:
    static void Request_Callback(evhttp_request* request, void *arg);
    void EventLoop();

private:
    RecvCallback recv_callback_;

    std::string listen_addr_;
    unsigned short listen_port_;

    event_base* evbase_;
    evhttp* evhttp_;
    evhttp_bound_socket* evhandle;

    kw::Thread thread_loop_;
};

}

#endif // CPPREST_HTTPSERVER_H
