#ifndef CPPREST_H
#define CPPREST_H

#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <mutex.h>
#include <Singleton.h>
#include <map>
#include "irequest.h"
#include "iresponse.h"

namespace cpprest
{

struct Handler
{
    typedef struct IResponse MT_Func();
    virtual struct IResponse Run(MT_Func placeholder, cpprest::IRequest& req) = 0;
};

struct HandlerInfo
{
    typedef std::map<std::string, std::string> MT_ParamInfo;

    int line_;
    const char* file_;
    const char* class_name_;
    std::map<std::string, std::string> param_info_;

    Handler* handler_;
};

class CppRest
{
public:
    typedef std::vector<HandlerInfo*> MT_HandlerInfos;

public:
    CppRest();

    void Register(HandlerInfo* handler_info);
    void UnRegister(HandlerInfo* handler_info);

    HandlerInfo* FindByPath(const char* path, int len);

    IResponse Dispatch(IRequest &request);

private:
    MT_HandlerInfos m_Handlers;
    kw::Mutex mutex;
};

#define CppRestSingleton kw::Singleton<cpprest::CppRest>::Instance()

}

inline const char* skip_space(const char* str)
{
    while(' ' != *str)
        str++;

    return str;
}

template<class T>
cpprest::HandlerInfo* MakeHandlerInfo(int line, const char* file, const char* class_name,
                                      const char* param_info)
{
    cpprest::HandlerInfo* handler_info = new cpprest::HandlerInfo();
    handler_info->line_ = line;
    handler_info->file_ = file;
    handler_info->class_name_ = class_name;

    handler_info->handler_ = new T();

    //format Path="/test", Method="Get"
    while(0 != param_info)
    {
        const char* eq_pos = strchr(param_info, '=');
        const char* left_dq = strchr(eq_pos, '"');
        const char* right_dq = strchr(left_dq + 1, '"'); //if val str contain double quote, will has some problem.
        const char* comma_pos = strchr(eq_pos, ',');

        if(0 == eq_pos)
            break;

        int key_str_len = eq_pos - param_info;
        int val_str_len = right_dq - left_dq - 1;

        std::string key_str(param_info, key_str_len);
        std::string val_str(left_dq + 1, val_str_len);

        //transform all letter to lower
        std::transform(key_str.begin(), key_str.end(), key_str.begin(), ::tolower);

        handler_info->param_info_[key_str] = val_str;
        param_info = comma_pos;
    }

    CppRestSingleton.Register(handler_info);
    return handler_info;
}

#define CONCAT_IMPL(X, Y) X##Y
#define MACRO_CONCAT(X, Y) CONCAT_IMPL(X, Y)

#define Route_(Name, ParamStr) \
    class Name : public cpprest::Handler \
    { \
    public: \
        Name(){} \
        struct cpprest::IResponse Run(MT_Func, cpprest::IRequest& req); \
    private: \
        static cpprest::HandlerInfo* HandlerInfo_; \
    }; \
    cpprest::HandlerInfo* Name::HandlerInfo_ = MakeHandlerInfo<Name>(__LINE__, __FILE__, #Name, ParamStr); \
    struct cpprest::IResponse Name::Run(

#define $Route(arg...) Route_(MACRO_CONCAT(HandlerClass, __COUNTER__), #arg)
#define __rph ),
#define Request __rph cpprest::IRequest
#define Response struct cpprest::IResponse

#endif // CPPREST_H
