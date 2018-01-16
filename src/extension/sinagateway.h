#ifndef OZ_SINAGATEWAY_H
#define OZ_SINAGATEWAY_H
#include "abstract/gatewayabstract.h"
namespace oz {

class CancelOrderRequest;
class OrderRequest;
class SubscribeRequest;

class SinaGateway : public GatewayAbstract
{
    Q_OBJECT
public:
    SinaGateway();
    ~SinaGateway();
    virtual void connectServer() override;
    virtual void closeServer() override;
    virtual void queryAccount() override;
    virtual void queryPosition() override;
    virtual void sendOrder(OrderRequest* request) override;
    virtual void cancelOrder(CancelOrderRequest* request) override;
    virtual void Subscribe(SubscribeRequest* request) override;
protected slots:
    void pull();
private:
    class SinaGatewayPrivate* const d;
};
}

#endif // OZ_SINAGATEWAY_H
