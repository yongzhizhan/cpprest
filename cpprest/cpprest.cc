#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpprest.h"

namespace cpprest
{

CppRest::CppRest()
{
}

void CppRest::Register(HandlerInfo* handler_info)
{
    kw::MutexGuard guard(mutex);
    m_Handlers.push_back(handler_info);
}

void CppRest::UnRegister(HandlerInfo* handler_info)
{
    kw::MutexGuard guard(mutex);
    MT_HandlerInfos::iterator tIter = std::find(m_Handlers.begin(), m_Handlers.end(), handler_info);

    if(m_Handlers.end() == tIter)
        return;

    m_Handlers.erase(tIter);
}

HandlerInfo* CppRest::FindByPath(const char* path, int len)
{
    kw::MutexGuard guard(mutex);
    for(MT_HandlerInfos::iterator tIter = m_Handlers.begin(); m_Handlers.end() != tIter; ++tIter)
    {
        HandlerInfo* handler_info = (HandlerInfo*)*tIter;

        printf("debug check path:%s\n", path);

        if(handler_info->param_info_["path"] != path)
            continue;

        return handler_info;
    }

    return 0;
}

IResponse CppRest::Dispatch(IRequest& request)
{
    printf("On Request Path:%s\n", request.path_.c_str());
    HandlerInfo* handler_info = FindByPath(request.path_.c_str(), request.path_.length());
    if(0 == handler_info)
    {
        IResponse response;
        char error[] = "path not exits.";
        response.content_.Append(error, sizeof error);

        return response;
    }

    IResponse response = handler_info->handler_->Run(0, request);

    cpprest::HandlerInfo::MT_ParamInfo::iterator iter = handler_info->param_info_.find("method");
    if(handler_info->param_info_.end() != iter)
        response.headers_["Content-Type"] = iter->second;

    return response;
}

}
