#ifndef OZ_DATATYPE_H
#define OZ_DATATYPE_H
#include <QString>
namespace oz {
class TickInfo {
public:
    enum OrderSequenceType {
        InvalidOrder = -1,
        FirstOrder = 0,
        SecondOrder,
        ThirdOrder,
        FourthOrder,
        FifthOrder,
        SixthOrder,
        SeventhOrder,
        EighthOrder,
        NinethOrder,
        TenthOrder
    };
    virtual ~TickInfo() {}
    virtual QString ticker() const = 0;
    virtual double averagePrice() const = 0;
    virtual double lastPrice() const = 0;
    virtual double preClosePrice() const = 0;
    virtual double openPrice() const = 0;
    virtual double closePrice() const = 0;
    virtual double highPrice() const = 0;
    virtual double lowPrice() const = 0;
    virtual quint64 volume() const = 0;
    virtual double turnover() const = 0;
    virtual double bidPrice(OrderSequenceType which) const = 0;
    virtual quint64 bidVolume(OrderSequenceType which) const = 0;
    virtual double askPrice(OrderSequenceType which) const = 0;
    virtual quint64 askVolume(OrderSequenceType which) const = 0;
    virtual qint32 date() const = 0; // YYYYMMDD
    virtual qint32 day() const = 0;
    virtual qint32 hour() const = 0;
    virtual qint32 minute() const = 0;
    virtual qint32 second() const = 0;
    virtual qint32 millisecond() const = 0;
    virtual quint64 msecsSinceEpoch() const = 0;
};

class TradeInfo {
public:
    virtual ~TradeInfo(){};
};

class OrderInfo {
public:
    virtual ~OrderInfo(){};
};

class AccountInfo {
public:
    virtual ~AccountInfo(){};
};

class PoisitionInfo {
public:
    virtual ~PoisitionInfo(){};
};

class LogInfo {
public:
    virtual ~LogInfo(){};
};

class ContractInfo {
public:
    virtual ~ContractInfo(){};
};

class OrderRequest {
public:
    virtual ~OrderRequest(){};
};

} // namespace oz
#endif // OZ_DATATYPE_H
