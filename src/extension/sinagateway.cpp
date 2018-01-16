#include "sinagateway_p.h"
#include "abstract/datatypes.h"
#include "sinadatatypes.h"
#include <cstring>
#include <QTextCodec>
#include <QDebug>
namespace oz {
static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    SinaGatewayPrivate* p = (SinaGatewayPrivate*) userp;
    struct MemoryStruct* mem = &p->received; //(struct MemoryStruct*)userp;

    mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        // std::cerr << "not enough memory (realloc returned NULL)" << std::endl;
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

SinaGatewayPrivate::SinaGatewayPrivate(SinaGateway* q) : q(q)
{
    curlHandler = curl_easy_init();
}
SinaGatewayPrivate::~SinaGatewayPrivate()
{
    thread.quit();
    curl_easy_cleanup(curlHandler);
}

const QString prefixUri = "http://hq.sinajs.cn/list=";

void SinaGatewayPrivate::fetch() {
    
    if (urls.isEmpty()) {
        return;
    }
    received.memory = (char*)malloc(1);
    received.size = 0;
    QString urlsString = urls.join(',');
    urlsString.prepend(prefixUri);
//     qCritical() << __PRETTY_FUNCTION__ << urlsString;
    curl_easy_setopt(curlHandler, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curlHandler, CURLOPT_WRITEDATA, (void*)this);
    curl_easy_setopt(curlHandler, CURLOPT_USERAGENT, "libcurl-agent/1.0");
    curl_easy_setopt(curlHandler, CURLOPT_URL, (void*)urlsString.toLocal8Bit().constData());
    auto res = curl_easy_perform(curlHandler);
    if (res == CURLE_OK) {
        QByteArray buffer(received.memory, received.size);
        QString converted =QTextCodec::codecForName( "GBK")->toUnicode(buffer);
//         qCritical() << converted;
        auto data = converted.split('\n');
        for (auto& datum : data) {
            if (datum.isEmpty()) {
                return;
            }
            auto tick = new SinaTickInfo(datum);
            emit q->hasTick(tick);
        }
    }
    else {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    received.size = 0;
    free(received.memory);
}



SinaGateway::SinaGateway() : d(new SinaGatewayPrivate(this))
{
    curl_global_init(CURL_GLOBAL_ALL);

    d->timer = new QTimer(this);
    connect(d->timer, SIGNAL(timeout()), this, SLOT(pull()));
    moveToThread(&d->thread);
    d->thread.start();
    d->timer->setInterval(3000);
    QMetaObject::invokeMethod(d->timer, "start");
}

SinaGateway::~SinaGateway() {

}

//     virtual void connectServer() override;
//     virtual void closeServer() override;
//     virtual void queryAccount() override;
//     virtual void queryPosition() override;
//     virtual void sendOrder(OrderRequest* request) override;
//     virtual void cancelOrder(CancelOrderRequest* request) override;
//     virtual void Subscribe(SubscribeRequest* request) override;
void SinaGateway::connectServer()
{
    // do nothing
}

void SinaGateway::closeServer()
{
}

void SinaGateway::Subscribe(SubscribeRequest* request)
{
    d->urls.append(request->ticker());
}

void SinaGateway::cancelOrder(CancelOrderRequest* request)
{
}

void SinaGateway::queryAccount()
{
}

void SinaGateway::queryPosition()
{
}


void SinaGateway::sendOrder(OrderRequest* request)
{
}

void oz::SinaGateway::pull()
{
    d->fetch();
}

}
