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

    kw::shared_ptr<cpprest::Response> foo(const kw::shared_ptr<cpprest::Request>& request)
    {
        kw::shared_ptr<cpprest::Response> response(new cpprest::Response);
        response->code_ = 200;
        response->content_.Append("i am test....");

        return response;
    }

    kw::shared_ptr<cpprest::Response> DelaySend(const kw::shared_ptr<cpprest::Request>& request)
    {
        kw::Thread thread(std::tr1::bind(&CpprestTest::DelaySendThread, this, request));
        thread.Start();

        return kw::shared_ptr<cpprest::Response>();
    }

    cpprest::RouteItems GetRouteItems()
    {
        cpprest::RouteItems items;
        cpprest::RouteItem item;

        item.path = "/test";
        item.method = cpprest::Method_Get;
        item.functor = std::tr1::bind(&CpprestTest::foo, this, std::tr1::placeholders::_1);

        items.push_back(item);

        item.path = "/delay_send";
        item.method = cpprest::Method_Get;
        item.functor = std::tr1::bind(&CpprestTest::DelaySend, this, std::tr1::placeholders::_1);

        items.push_back(item);

        return items;
    }

    void DelaySendThread(const kw::shared_ptr<cpprest::Request>& request)
    {
        sleep(30);
        kw::shared_ptr<cpprest::Response> response(new cpprest::Response);
        response->code_ = 200;
        response->content_.Append("delay send");

        rest_frame->Reply(request->RequestHandler(), response);
    }

    void StopRest()
    {
        sleep(100);
        rest_frame->Stop();
    }

protected:
    kw::shared_ptr<cpprest::CppRest> rest_frame;
};

TEST_F(CpprestTest, Default)
{
    int thread_count = 5;
    const char* host = "0.0.0.0";
    unsigned short port = 12345;

    printf("listen on %s:%d, thread:%d...\n", host, port, thread_count);

    cpprest::RouteItems items = GetRouteItems();
    rest_frame.reset(new cpprest::CppRest(host, port, thread_count, items));
    rest_frame->Start();

    kw::Thread thread(std::tr1::bind(&CpprestTest::StopRest, this));
    thread.Start();

    rest_frame->Join();
}

TEST_F(CpprestTest, DelaySend)
{
    int thread_count = 5;
    const char* host = "0.0.0.0";
    unsigned short port = 12345;

    printf("DelaySend -> listen on %s:%d, thread:%d...\n", host, port, thread_count);

    cpprest::RouteItems items = GetRouteItems();
    rest_frame.reset(new cpprest::CppRest(host, port, thread_count, items));
    rest_frame->Start();

    kw::Thread thread(std::tr1::bind(&CpprestTest::StopRest, this));
    thread.Start();

    rest_frame->Join();
}
