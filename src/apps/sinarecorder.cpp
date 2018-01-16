#include "extension/sinagateway.h"
#include "core/defaultengine.h"
#include "core/recordstrategy.h"
#include "extension/sinadatatypes.h"
#include <QCoreApplication>

int main (int argc, char* argv[]) {
    QCoreApplication app(argc, argv);
    oz::DefaultEngine engine;
    auto gatewayId = engine.addGateway(new oz::SinaGateway);
    auto strategy = new oz::RecordStrategy;
    engine.addStrategy(strategy);
    // TODO use signal slot connection to elimite this
    strategy->setEngine(&engine);
    engine.connectServer();
    oz::SinaSubscribeRequest r1("sz002405");
    oz::SinaSubscribeRequest r2("sz002268");
    engine.Subscribe(&r1, gatewayId);
    engine.Subscribe(&r2, gatewayId);
    return app.exec();
}
