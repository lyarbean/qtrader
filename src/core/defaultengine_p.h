#ifndef DEFAULTENGINEPRIVATE_H
#define DEFAULTENGINEPRIVATE_H
#include <QMap>

namespace oz {
class StrategyAbstract;

class DefaultEnginePrivate {
public:
    DefaultEnginePrivate(DefaultEngine* q);
    virtual ~DefaultEnginePrivate();

private:
    friend class DefaultEngine;
    DefaultEngine* const q;
    QMap<QUuid, StrategyAbstract*> strategies;
    QMap<QUuid, GatewayAbstract*> gateways;
};
} // namespace oz

#endif // DEFAULTENGINEPRIVATE_H
