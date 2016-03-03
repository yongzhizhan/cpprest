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
#include <signal_slot.h>
#include "request.h"
#include "response.h"

namespace cpprest
{

class HttpServer : public boost::noncopyable
{
public:
    typedef kw::Signal<void(void*, kw::shared_ptr<Request>&)> RecvSignal;

    HttpServer		(const char* listen_addr="0.0.0.0", unsigned short listen_port=8080);
    ~HttpServer		(void);

    bool Start();
    bool Stop();
    void Join();

    void Reply(void* req_handle, kw::shared_ptr<Response>& response);

    void SetPort(unsigned short port) { listen_port_ = port; }
    void SetHost(kw::StringArg addr) { listen_addr_ = addr.data(); }

private:
    static void Request_Callback(evhttp_request* request, void* arg);
    static void EventTimer(evutil_socket_t fd, short flag, void* arg);
    void EventLoop();

public:
     RecvSignal recv_signal_;

private:
    event_base* evbase_;
    event* evtimer_;
    evhttp* evhttp_;
    evhttp_bound_socket* evhandle;
    bool break_loop_;

    kw::Thread thread_loop_;

    std::string listen_addr_;
    unsigned short listen_port_;
};

}

#endif // CPPREST_HTTPSERVER_H
