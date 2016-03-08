#include "request.h"

namespace cpprest{

Request::Request(evhttp_request* req_handler)
    :req_handler_(req_handler)
{
    evhttp_parse_query(evhttp_request_get_uri(req_handler_), &params_);
}

Request::~Request()
{
    evhttp_clear_headers(&params_);
}

const char* Request::Path()
{
    return evhttp_request_get_uri(req_handler_);
}

Method Request::ReqMethod()
{
    switch (evhttp_request_get_command(req_handler_))
    {
        case EVHTTP_REQ_GET:		return Method_Get;
        case EVHTTP_REQ_POST: 		return Method_Post;
        case EVHTTP_REQ_PUT: 		return Method_Put;
        case EVHTTP_REQ_DELETE: 	return Method_Delete;
        default: 					return Method_UnDefine;
    }
}

std::string Request::Header(kw::StringArg key, int len)
{
    evkeyvalq* headers = evhttp_request_get_input_headers(req_handler_);
    for(evkeyval* header = headers->tqh_first; header; header = header->next.tqe_next)
    {
        if(0 == strncmp(key.data(), header->key, len))
            return header->value;
    }

    return "";
}

kw::shared_ptr<kw::MemoryBuffer> Request::Content()
{
    if(0 == content_)
    {
        content_.reset(new kw::MemoryBuffer);

        evbuffer* input_buf = evhttp_request_get_input_buffer(req_handler_);
        while (evbuffer_get_length(input_buf))
        {
            char cbuf[128];
            int count = evbuffer_remove(input_buf, cbuf, sizeof(cbuf));
            if (count <= 0)
                continue;

            content_->Append(cbuf);
        }
    }

    return content_;
}

const char* Request::GetParamS(const char* name, const char* def)
{
    const char* val = evhttp_find_header(&params_, name);
    return 0 == val ? def : val;
}

int Request::GetParamI(const char* name, int def)
{
    const char* val = evhttp_find_header(&params_, name);
    return 0 == val ? def : atoi(val);
}

evhttp_request* Request::RequestHandler()
{
    return req_handler_;
}

}
