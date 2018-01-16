#ifndef RECORDSTRATEGYPRIVATE_H
#define RECORDSTRATEGYPRIVATE_H
#include <QMap>
namespace oz {
class EngineAbstract;
class RecordStrategy;
class RecordStrategyPrivate {
public:
    RecordStrategyPrivate(RecordStrategy* q);
    virtual ~RecordStrategyPrivate();
    RecordStrategy* const q;
    EngineAbstract* engine;
    QMap<QString, double> bidPrice;
    QMap<QString, double> askPrice;
};
} // namespace oz

#endif // RECORDSTRATEGYPRIVATE_H
