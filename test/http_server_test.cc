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

    void RecvCallback(void* req_handle, const cpprest::Request& req)
    {
        kw::shared_ptr<cpprest::Response> response(new cpprest::Response);

        http_server_->Reply(req_handle, response);
    }

    void RecvCallbackDealy(void* req_handle, const cpprest::Request& req)
    {
        cur_req_handle_ = req_handle;
        thread_.Start();
    }

    void ReplayDelay()
    {
        kw::shared_ptr<cpprest::Response> response(new cpprest::Response);

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
}

TEST_F(HttpServerTest, Delay)
{
}
