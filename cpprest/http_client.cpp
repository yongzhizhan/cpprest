#include "http_client.h"
#include "request.h"
#include "response.h"

namespace cpprest{

HttpClient::HttpClient()
{
}

HttpClient::~HttpClient()
{
}

Response HttpClient::Send(const Request& request, int timeout_ms)
{
    event_base* base = event_base_new();
    event_base_dispatch(base);

    event_base_free(base);

    Response response;
    return response;
}

}
