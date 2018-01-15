#ifndef RECORDSTRATEGYPRIVATE_H
#define RECORDSTRATEGYPRIVATE_H

namespace oz {
class EngineAbstract;
class RecordStrategy;
class RecordStrategyPrivate {
public:
    RecordStrategyPrivate(RecordStrategy* q);
    virtual ~RecordStrategyPrivate();
    RecordStrategy* const q;
    EngineAbstract* engine;
};
} // namespace oz

#endif // RECORDSTRATEGYPRIVATE_H
