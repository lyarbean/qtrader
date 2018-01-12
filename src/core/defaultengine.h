#ifndef OZ_DEFAULTENGINE_H
#define OZ_DEFAULTENGINE_H
#include <QObject>
#include "abstract/engineabstract.h"

namespace oz {
class DefaultEnginePrivate;
class DefaultEngine : public QObject, public EngineAbstract {
    Q_OBJECT
public:
    explicit DefaultEngine();
    ~DefaultEngine();
    virtual void connectServer() override;
    virtual QUuid addStrategy(StrategyAbstract* strategy) override;
    virtual QUuid addGateway(GatewayAbstract* gateway) override;
    virtual RiskManager* riskManager() const override;
    virtual PositionManager* positionManager() const override;
    virtual void onTick(TickInfo* info) override;
    virtual void onTrade(TradeInfo* info) override;
    virtual void onOrder(OrderInfo* info) override;
    virtual void onPoisition(PoisitionInfo* info) override;
    virtual void onAccount(AccountInfo* info) override;
    virtual void onContract(ContractInfo* info) override;
    virtual void onLog(LogInfo* info) override;
    virtual void sendOrder(OrderRequest* request, const QUuid& gateway) override;
    virtual void cancelOrder(CancelOrderRequest* request, const QUuid& gateway) override;
    virtual void Subscribe(SubscribeRequest* request, const QUuid& gateway) override;

private:
    DefaultEnginePrivate* const d;
};
} // namespace oz

#endif // OZ_DEFAULTENGINE_H
