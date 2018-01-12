#ifndef OZ_RECORDSTRATEGY_H
#define OZ_RECORDSTRATEGY_H
#include "abstract/strategyabstract.h"
namespace oz {

class RecordStrategy : StrategyAbstract {
public:
    RecordStrategy();
    virtual void onTick(TickInfo* info) override;
    virtual void onTrade(TradeInfo* info) override;
    virtual void onOrder(OrderInfo* info) override;

private:
    class RecordStrategyPrivate* const d;
};
} // namespace oz

#endif // OZ_RECORDSTRATEGY_H
