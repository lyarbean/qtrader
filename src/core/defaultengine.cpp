#include "defaultengine.h"
#include "defaultengine_p.h"
#include "abstract/strategyabstract.h"
#include "abstract/gatewayabstract.h"
#include "abstract/datatypes.h"
#include "riskmanager.h"
using namespace oz;

DefaultEnginePrivate::DefaultEnginePrivate(DefaultEngine* q)
  : q(q) {
}
DefaultEnginePrivate::~DefaultEnginePrivate() {
}

DefaultEngine::DefaultEngine()
  : d(new DefaultEnginePrivate(this)) {
}

DefaultEngine::~DefaultEngine() {
    delete d;
}

void DefaultEngine::connectServer() {
    for (auto g : d->gateways)
        g->connectServer();
}
QUuid DefaultEngine::addStrategy(StrategyAbstract* strategy) {
    QUuid uuid = QUuid::createUuid();
    d->strategies[uuid] = strategy;
    // strategy->setEngine(this);
    return uuid;
}

QUuid DefaultEngine::addGateway(GatewayAbstract* gateway) {
    QUuid uuid = QUuid::createUuid();
    d->gateways[uuid] = gateway;
    connect(gateway, &GatewayAbstract::hasTick, this, &DefaultEngine::onTick);
    connect(gateway, &GatewayAbstract::hasTrade, this, &DefaultEngine::onTrade);
    connect(gateway, &GatewayAbstract::hasOrder, this, &DefaultEngine::onOrder);
    connect(gateway, &GatewayAbstract::hasPoisition, this, &DefaultEngine::onPoisition);
    connect(gateway, &GatewayAbstract::hasAccount, this, &DefaultEngine::onAccount);
    connect(gateway, &GatewayAbstract::hasContract, this, &DefaultEngine::onContract);
    connect(gateway, &GatewayAbstract::hasLog, this, &DefaultEngine::onLog);
    return uuid;
}

RiskManager* DefaultEngine::riskManager() const {
    return nullptr;
}

PositionManager* DefaultEngine::positionManager() const {
    return nullptr;
}

void DefaultEngine::onTick(TickInfo* info) {
    for (auto s : d->strategies) {
        s->onTick(info);
    }
    delete info;
}

void DefaultEngine::onTrade(TradeInfo* info) {
    for (auto s : d->strategies) {
        s->onTrade(info);
    }
    delete info;
}

void DefaultEngine::onOrder(OrderInfo* info) {
    for (auto s : d->strategies) {
        s->onOrder(info);
    }
    delete info;
}

void DefaultEngine::sendOrder(OrderRequest* request, const QUuid& gateway) {
    if (!d->riskManager->check(request, gateway)) {
        // TODO 
        // request->status = HasRisk;
        return;
    }
    auto g = d->gateways.find(gateway);
    if (g == d->gateways.end()) {
        // TODO 
        // request->status = NoGatway;
        return;
    }
    g.value()->sendOrder(request); // ownership return to caller (strategy)
}

void DefaultEngine::cancelOrder(CancelOrderRequest* request, const QUuid& gateway) {
    // d->riskManager->check()
    auto g = d->gateways.find(gateway);
    if (g == d->gateways.end()) {
        // TODO 
        // request->status = NoGatway;
        return;
    }
    g.value()->cancelOrder(request); // ownership return to caller (strategy)
}

// TODO use a map to ease onTick
// {strategy + gateway => symbol}
// {symbol + gateway ==> strategy}
// When a gateway emits a TickInfo, it adds gatewayname to TickInfo::gateway
// SubscribeRequest has a uuid to indicate which strategy sends the request


void DefaultEngine::Subscribe(SubscribeRequest* request, const QUuid& gateway) {
    // d->riskManager->check()
    auto g = d->gateways.find(gateway);
    if (g == d->gateways.end()) {
        // TODO 
        // request->status = NoGatway;
        return;
    }
    g.value()->Subscribe(request); // ownership return to caller (strategy)
}
