#include <tr1/memory>
#include <tr1/functional>
#include <http_server.h>
#include <cpprest.h>


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

    items.push_back(item);

    cpprest::CppRest rest_frame(host, port, thread_count, items);
    rest_frame.Start();

    getchar();

    rest_frame.Stop();
}
