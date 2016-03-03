#ifndef ZSHARE_DEFINE
#define ZSHARE_DEFINE

#include <tr1/functional>
#include <vector>
#include <map>
#include <string>
#include <shared_lib.h>

namespace cpprest{

class Request;
class Response;

typedef std::tr1::function<kw::shared_ptr<Response>(const kw::shared_ptr<Request>&)> MappingFunctor;

enum Method
{
    Method_UnDefine, Method_Get, Method_Put, Method_Post, Method_Delete
};

enum MIMEType
{
    MIMEType_UnDefine, MIMEType_Text_Plain, MIMEType_Application_Json
};

struct RouteItem
{
    const char* path;
    MappingFunctor functor;
    Method method;
    MIMEType consume;
    MIMEType produce;
};

typedef std::map<std::string, std::string> HttpHeaders;
typedef std::vector<RouteItem> RouteItems;

}
#endif // ZSHARE_DEFINE

