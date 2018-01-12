#ifndef OZ_ENGINEABSTRACT_H
#define OZ_ENGINEABSTRACT_H
#include <QUuid>
namespace oz {

class GatewayAbstract;
class StrategyAbstract;
class RiskManager;
class PositionManager;

class AccountInfo;
class ContractInfo;
class LogInfo;
class OrderInfo;
class PoisitionInfo;
class TickInfo;
class TradeInfo;

class CancelOrderRequest;
class OrderRequest;
class SubscribeRequest;


class EngineAbstract
{
public:
virtual void connectServer() = 0;
virtual QUuid addStrategy(StrategyAbstract* strategy) = 0;
virtual QUuid addGateway(GatewayAbstract* gateway) = 0;
virtual RiskManager* riskManager() const = 0;
virtual PositionManager* positionManager() const = 0;
virtual void onTick(TickInfo* info) = 0;
virtual void onTrade(TradeInfo* info) = 0;
virtual void onOrder(OrderInfo* info) = 0;
virtual void onPoisition(PoisitionInfo* info) = 0;
virtual void onAccount(AccountInfo* info) = 0;
virtual void onContract(ContractInfo* info) = 0;
virtual void onLog(LogInfo* info) = 0;
virtual void sendOrder(OrderRequest* request, const QUuid& gateway) = 0;
virtual void cancelOrder(CancelOrderRequest* request, const QUuid& gateway) = 0;
virtual void Subscribe(SubscribeRequest* request, const QUuid& gateway) = 0;
};
}

#endif // OZ_ENGINEABSTRACT_H
