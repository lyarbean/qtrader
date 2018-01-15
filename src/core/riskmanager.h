#ifndef OZ_RISKMANAGER_H
#define OZ_RISKMANAGER_H

class QUuid;
namespace oz {
class OrderRequest;
class RiskManager
{
public:
    RiskManager();
    bool check(OrderRequest* request, const QUuid& gateway);
};

}
#endif // OZ_RISKMANAGER_H
