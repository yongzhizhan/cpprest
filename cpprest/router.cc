#include "router.h"

namespace cpprest {

Router::Router(const RouteItems &route_items, int thread_count)
    :route_items_(route_items), thread_pool_(thread_count, "router")
{
    thread_pool_.Start();
}

Router::~Router()
{
    thread_pool_.Stop();
}

void Router::OnRecv(void* handle, kw::shared_ptr<Request>& request)
{
   thread_pool_.Run(std::tr1::bind(&Router::Run, this, handle, request));
}

void Router::Run(void* handle, kw::shared_ptr<Request>& request)
{
    printf("Run....\n");

    //multiply thread read is safe
    for(RouteItems::iterator iter = route_items_.begin(); iter != route_items_.end(); ++iter)
    {
        //filter path
        if(iter->path != request->path_)
            continue;

        //filter get post delete put
        if(Method_UnDefine != request->method && iter->method != request->method)
            continue;

        //execute functor
        kw::shared_ptr<Response> response = iter->functor(request);
        reply_signal_.Emit(handle, response);
        return;
    }

    kw::shared_ptr<Response> response(new Response);
    response->code_ = 501;
    reply_signal_.Emit(handle, response);

    //TODO: add log
    printf("error...\n");
}

}
