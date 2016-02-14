#include <gtest/gtest.h>
#include "http_server.h"

class HttpServerTest : public testing::Test
{
public:
    HttpServerTest()
        :thread_(std::tr1::bind(&HttpServerTest::ReplayDelay, this))
    {

    }

    void SetUp()
    {

    }

    void TearDown()
    {

    }

    void RecvCallback(void* req_handle, const cpprest::IRequest& req)
    {
        cpprest::IResponse response;

        http_server_->Reply(req_handle, response);
    }

    void RecvCallbackDealy(void* req_handle, const cpprest::IRequest& req)
    {
        cur_req_handle_ = req_handle;
        thread_.Start();
    }

    void ReplayDelay()
    {
        cpprest::IResponse response;

        sleep(3);
        http_server_->Reply(cur_req_handle_, response);
    }

protected:
    std::tr1::shared_ptr<cpprest::HttpServer> http_server_;
    kw::Thread thread_;
    void* cur_req_handle_;
};

TEST_F(HttpServerTest, Default)
{
    return;
    http_server_.reset(new cpprest::HttpServer("0.0.0.0", 12345));
    http_server_->SetRecvCallback(std::tr1::bind(&HttpServerTest::RecvCallback, this,
                                                 std::tr1::placeholders::_1,
                                                 std::tr1::placeholders::_2));
    http_server_->Start();

    sleep(2);

    http_server_->Stop();
}

TEST_F(HttpServerTest, Delay)
{
    http_server_.reset(new cpprest::HttpServer("0.0.0.0", 54321));
    http_server_->SetRecvCallback(std::tr1::bind(&HttpServerTest::RecvCallbackDealy, this,
                                                 std::tr1::placeholders::_1,
                                                 std::tr1::placeholders::_2));
    http_server_->Start();

    sleep(1500);

    http_server_->Stop();
}
