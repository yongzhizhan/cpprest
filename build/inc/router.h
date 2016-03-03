#ifndef CPPREST_ROUTER_H
#define CPPREST_ROUTER_H

#include <tr1/memory>
#include <tr1/functional>
#include <string_arg.h>
#include <signal_slot.h>
#include <thread_pool.h>
#include <deque>
#include "zshare_def.h"
#include "request.h"
#include "response.h"

namespace cpprest
{

struct RecvItem
{
    void* handle;
    kw::weak_ptr<Request> request;
};

class Router
{
public:
    typedef kw::Signal<void(void* handle, kw::shared_ptr<Response>&)> ReplySignal;
    typedef std::deque<RecvItem> DequeRecvItem;

    Router(const RouteItems& route_items, int thread_count=1);
    ~Router();

    void OnRecv(void* handle, kw::shared_ptr<Request>& request);

    void Run(void *handle, kw::shared_ptr<Request> &request);

public:
     ReplySignal reply_signal_;

private:
    kw::ThreadPool thread_pool_;
    RouteItems route_items_;

    kw::Mutex mutex_;
    DequeRecvItem recv_items_;
};

}
#endif // ROUTER_H
