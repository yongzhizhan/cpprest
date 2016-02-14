#include <gtest/gtest.h>
#include <tr1/memory>
#include <tr1/functional>
#include <cpprest.h>
#include <http_server.h>

class CpprestTest : public testing::Test
{
public:
    void SetUp()
    {
    }

    void TearDown()
    {

    }

    void RecvCallback(void* req_handle, cpprest::IRequest& req)
    {
        cpprest::IResponse response = CppRestSingleton.Dispatch(req);
        http_server_->Reply(req_handle, response);
    }

protected:
    std::tr1::shared_ptr<cpprest::HttpServer> http_server_;
};

TEST_F(CpprestTest, Default)
{
    http_server_.reset(new cpprest::HttpServer("0.0.0.0", 12345));
    http_server_->SetRecvCallback(std::tr1::bind(&CpprestTest::RecvCallback, this,
                                                 std::tr1::placeholders::_1,
                                                 std::tr1::placeholders::_2));
    http_server_->Start();

    //TODO: fix this test, use http client
    sleep(2);

    http_server_->Stop();
}

$Route(Path="/test", Consume="text/plain", Produce="application/json")
Response test(Request& request)
{
    printf("request:%s\n", request.content_.Data());
    Response response;

    char buf[] = "12345";
    response.content_.Append(buf, sizeof buf);

    return response;
}

$Route(Path="/test2", Consume="text/plain", Produce="application/json")
Response test2(Request& path)
{
    Response response;
    return response;
}

$Route(Path="/Method", Method="Get")
Response method_test(Request& path)
{
    Response response;
    return response;
}






