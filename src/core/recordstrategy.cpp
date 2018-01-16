#include "recordstrategy.h"
#include "recordstrategy_p.h"
#include "abstract/datatypes.h"
#include <QDebug>
using namespace oz;

RecordStrategyPrivate::RecordStrategyPrivate(RecordStrategy* q)
  : q(q) {
}
RecordStrategyPrivate::~RecordStrategyPrivate() {
}

RecordStrategy::RecordStrategy()
  : d(new RecordStrategyPrivate(this)) {
}

void RecordStrategy::onTick(TickInfo* info) {
    auto ask = d->askPrice[info->ticker()];
    auto bid = d->bidPrice[info->ticker()];
    if (ask != info->askPrice(TickInfo::FirstOrder) || bid != info->bidPrice(TickInfo::FirstOrder)) {
        qCritical() << info->ticker() << info->tickerName() << info->bidPrice(TickInfo::FirstOrder) << info->askPrice(TickInfo::FirstOrder);
        d->askPrice[info->ticker()] = info->askPrice(TickInfo::FirstOrder);
        d->bidPrice[info->ticker()] = info->bidPrice(TickInfo::FirstOrder);
    } 
}

void RecordStrategy::onTrade(TradeInfo* info) {
}
void RecordStrategy::onOrder(OrderInfo* info) {
}

void RecordStrategy::setEngine(EngineAbstract* engine) {
    d->engine = engine;
}
