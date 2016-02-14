#include <tr1/memory>
#include <tr1/functional>
#include <http_server.h>
#include <cpprest.h>

class CpprestServer
{
public:
    void RecvCallback(void* req_handle, cpprest::IRequest& req)
    {
        cpprest::IResponse response = CppRestSingleton.Dispatch(req);
        http_server_->Reply(req_handle, response);
    }

    void Start(unsigned short port)
    {
        http_server_.reset(new cpprest::HttpServer("0.0.0.0", port));
        http_server_->SetRecvCallback(std::tr1::bind(&CpprestServer::RecvCallback, this,
                                                     std::tr1::placeholders::_1,
                                                     std::tr1::placeholders::_2));
        http_server_->Start();
    }

    void Stop()
    {
        http_server_->Stop();
    }

protected:
    std::tr1::shared_ptr<cpprest::HttpServer> http_server_;
};

int main()
{
    CpprestServer cpprest_server;

    unsigned short port = 12345;
    printf("listen on %d...\n", port);

    cpprest_server.Start(port);

    getchar();

    cpprest_server.Stop();
}
