#include "defaultengine.h"
#include "defaultengine_p.h"
#include "abstract/strategyabstract.h"
#include "abstract/gatewayabstract.h"
#include "abstract/datatypes.h"

using namespace oz;

DefaultEnginePrivate::DefaultEnginePrivate(DefaultEngine* q) : q(q)
{
}
DefaultEnginePrivate::~DefaultEnginePrivate()
{
}


DefaultEngine::DefaultEngine()
 : d(new DefaultEnginePrivate(this))
{

}

DefaultEngine::~DefaultEngine()
{
    delete d;

}

void DefaultEngine::connectServer() {
    for (auto g : d->gateways)
        g->connectServer();
}
QUuid DefaultEngine::addStrategy(StrategyAbstract* strategy)
{
    QUuid uuid = QUuid::createUuid();
    d->strategies[uuid] = strategy;
    // strategy->setEngine(this);
    return uuid;
}

QUuid DefaultEngine::addGateway(GatewayAbstract* gateway)
{
    QUuid uuid = QUuid::createUuid();
    d->gateways[uuid] = gateway;
    connect(gateway, &GatewayAbstract::onTick, this, &DefaultEngine::onTick);
    connect(gateway, &GatewayAbstract::onTrade, this, &DefaultEngine::onTrade);
    connect(gateway, &GatewayAbstract::onOrder, this, &DefaultEngine::onOrder);
    connect(gateway, &GatewayAbstract::onPoisition, this, &DefaultEngine::onPoisition);
    connect(gateway, &GatewayAbstract::onAccount, this, &DefaultEngine::onAccount);
    connect(gateway, &GatewayAbstract::onContract, this, &DefaultEngine::onContract);
    connect(gateway, &GatewayAbstract::onLog, this, &DefaultEngine::onLog);
    return uuid;
}

RiskManager* DefaultEngine::riskManager() const
{
    return nullptr;
}

PositionManager* DefaultEngine::positionManager() const
{
    return nullptr;
}

void DefaultEngine::onTick(TickInfo* info)
{
    for (auto s : d->strategies) {
        s->onTick(info);
    }
    delete info;
}

void DefaultEngine::onTrade(TradeInfo* info)
{
    for (auto s : d->strategies) {
        s->onTrade(info);
    }
    delete info;
}

void DefaultEngine::onOrder(OrderInfo* info)
{
    for (auto s : d->strategies) {
        s->onOrder(info);
    }
    delete info;
}

void DefaultEngine::sendOrder(OrderRequest* request, const QUuid& gateway)
{
    // d->riskManager->check()
    auto g = d->gateways.find(gateway);
    if (g == d->gateways.end()) {
        return;
    }
    g.value()->sendOrder(request); // gateway take the ownership of request
}

void DefaultEngine::cancelOrder(CancelOrderRequest* request, const QUuid& gateway)
{
    // d->riskManager->check()
    auto g = d->gateways.find(gateway);
    if (g == d->gateways.end()) {
        return;
    }
    g.value()->cancelOrder(request); // gateway take the ownership of request
}

void DefaultEngine::Subscribe(SubscribeRequest* request, const QUuid& gateway)
{
    // d->riskManager->check()
    auto g = d->gateways.find(gateway);
    if (g == d->gateways.end()) {
        return;
    }
    g.value()->Subscribe(request); // gateway take the ownership of request
}
