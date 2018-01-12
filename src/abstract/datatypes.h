#ifndef OZ_DATATYPE_H
#define OZ_DATATYPE_H
namespace oz {
class TickInfo {
public:
    virtual ~TickInfo() {};
    virtual double averagePrice() const = 0;
};

class TradeInfo {
public:
    virtual ~TradeInfo() {};
};

class OrderInfo {
public:
    virtual ~OrderInfo() {};
};

class AccountInfo {
public:
    virtual ~AccountInfo() {};
};

class PoisitionInfo {
public:
    virtual ~PoisitionInfo() {};
};


class LogInfo {
public:
    virtual ~LogInfo() {};
};

class ContractInfo {
public:
    virtual ~ContractInfo() {};
};

class OrderRequest {
public:
    virtual ~OrderRequest() {};
};


}
#endif // OZ_DATATYPE_H
