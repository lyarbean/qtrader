#ifndef DEFAULTENGINEPRIVATE_H
#define DEFAULTENGINEPRIVATE_H
#include <QMap>
#include <QThread>
namespace oz {
class StrategyAbstract;
class RiskManager;
class DefaultEnginePrivate {
public:
    DefaultEnginePrivate(DefaultEngine* q);
    virtual ~DefaultEnginePrivate();

private:
    friend class DefaultEngine;
    DefaultEngine* const q;
    QThread thread;
    RiskManager* riskManager;
    QMap<QUuid, StrategyAbstract*> strategies;
    QMap<QUuid, GatewayAbstract*> gateways;
};
} // namespace oz

#endif // DEFAULTENGINEPRIVATE_H
