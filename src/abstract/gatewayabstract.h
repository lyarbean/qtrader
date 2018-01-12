#ifndef OZ_GATEWAYABSTRACT_H
#define OZ_GATEWAYABSTRACT_H
#include <QObject>
namespace oz {
class CancelOrderRequest;
class OrderRequest;
class SubscribeRequest;

class AccountInfo;
class ContractInfo;
class LogInfo;
class OrderInfo;
class PoisitionInfo;
class TickInfo;
class TradeInfo;

class GatewayAbstract : public QObject {
    Q_OBJECT
public:
    virtual void connectServer() = 0;
    virtual void closeServer() = 0;
    virtual void queryAccount() = 0;
    virtual void queryPosition() = 0;
    virtual void sendOrder(OrderRequest* request) = 0;
    virtual void cancelOrder(CancelOrderRequest* request) = 0;
    virtual void Subscribe(SubscribeRequest* request) = 0;
signals:
    void onTick(TickInfo* info);
    void onTrade(TradeInfo* info);
    void onOrder(OrderInfo* info);
    void onPoisition(PoisitionInfo* info);
    void onAccount(AccountInfo* info);
    void onContract(ContractInfo* info);
    void onLog(LogInfo* info);
};
} // namespace oz

#endif // OZ_GATEWAYABSTRACT_H
