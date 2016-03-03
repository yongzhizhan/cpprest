#include <tr1/memory>
#include <tr1/functional>
#include <http_server.h>
#include <cpprest.h>

kw::shared_ptr<cpprest::Response> hello_functor(const kw::shared_ptr<cpprest::Request>& request)
{
    kw::shared_ptr<cpprest::Response> response;
    response->content_.Append("test");

    return response;
}

int main()
{
    const char* host = "0.0.0.0";
    int thread_count = 5;
    unsigned short port = 12345;
    printf("listen on %s:%d, thread:%d...\n", host, port, thread_count);

    cpprest::RouteItems items;
    cpprest::RouteItem item;

    item.path = "/test";
    item.method = cpprest::Method_Get;
    item.functor = std::tr1::bind(&hello_functor, std::tr1::placeholders::_1);

    items.push_back(item);

    cpprest::CppRest rest_frame(host, port, thread_count, items);
    rest_frame.Start();

    sleep(100);
    rest_frame.Stop();
}
