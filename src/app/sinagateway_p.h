#ifndef SINAGATEWAYPRIVATE_H
#define SINAGATEWAYPRIVATE_H
#include "sinagateway.h"
#include <curl/curl.h>

struct MemoryStruct {
    char* memory;
    size_t size;
};

namespace oz {

class SinaGatewayPrivate
{
public:
    SinaGatewayPrivate(SinaGateway* q);
    virtual ~SinaGatewayPrivate();
    void fetch(const QString& urls);
    class SinaGateway* const q;

    MemoryStruct received;
    CURL* curlHandler;
};
}

#endif // SINAGATEWAYPRIVATE_H
