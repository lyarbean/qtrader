#include "recordstrategy.h"
#include "recordstrategy_p.h"

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
}

void RecordStrategy::onTrade(TradeInfo* info) {
}
void RecordStrategy::onOrder(OrderInfo* info) {
}
