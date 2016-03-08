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
        printf("path:%s, request path:%s\n", iter->path, request->Path());
        if(0 != strncmp(iter->path, request->Path(), strlen(iter->path)))
            continue;

        //filter get post delete put
        if(Method_UnDefine != request->ReqMethod() && iter->method != request->ReqMethod())
            continue;

        //execute functor
        kw::shared_ptr<Response> response = iter->functor(request);
        if(0 != response)
            reply_signal_.Emit(handle, response);

        return;
    }

    kw::shared_ptr<Response> response(new Response);
    response->code_ = HTTP_NOTIMPLEMENTED;
    reply_signal_.Emit(handle, response);

    //TODO: add log
    printf("error, path:%s, method:%d...\n", request->Path(), request->ReqMethod());
}

}
