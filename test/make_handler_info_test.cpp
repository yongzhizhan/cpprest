#include <gtest/gtest.h>
#include <cpprest.h>

class MakeHandlerInfoTest : public testing::Test
{
public:
    void SetUp()
    {
    }

    void TearDown()
    {

    }
};

class Foo : public cpprest::Handler{
public:
    virtual struct cpprest::IResponse Run(MT_Func placeholder, cpprest::IRequest& req)
    {
        cpprest::IResponse rep;
        return rep;
    }
};

TEST_F(MakeHandlerInfoTest, Default)
{
    //format Path="/test", Method="Get"
    cpprest::HandlerInfo* handler_info = MakeHandlerInfo<Foo>(__LINE__, __FILE__,
                                                         "Test", "Path=\"test\"");

    EXPECT_STREQ(handler_info->param_info_["Path"].c_str(), "test");
    CppRestSingleton.UnRegister(handler_info);

    delete handler_info->handler_;
    delete handler_info;
}
