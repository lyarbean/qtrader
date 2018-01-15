#ifndef OZ_RECORDSTRATEGY_H
#define OZ_RECORDSTRATEGY_H
#include "abstract/strategyabstract.h"
namespace oz {
class RecordStrategyPrivate;
class RecordStrategy : StrategyAbstract {
public:
    RecordStrategy();
    virtual void setEngine(EngineAbstract* engine);
    virtual void onTick(TickInfo* info) override;
    virtual void onTrade(TradeInfo* info) override;
    virtual void onOrder(OrderInfo* info) override;

private:
    RecordStrategyPrivate* const d;
};
} // namespace oz

#endif // OZ_RECORDSTRATEGY_H
