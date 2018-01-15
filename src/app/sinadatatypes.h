#ifndef OZ_SINA_DATATYPE_H
#define OZ_SINA_DATATYPE_H
#include "abstract/datatypes.h"

namespace oz {
class SinaTickInfoPrivate;
class SinaTickInfo : public TickInfo {
public:
    explicit SinaTickInfo(const QString& source);
    ~SinaTickInfo();
    virtual QString ticker() const override;
    void setTicker(QString&);
    virtual double averagePrice() const override;
    virtual double lastPrice() const override;
    virtual double preClosePrice() const override;
    virtual double openPrice() const override;
    virtual double closePrice() const override;
    virtual double highPrice() const override;
    virtual double lowPrice() const override;
    virtual quint64 volume() const override;
    virtual double turnover() const override;
    virtual double bidPrice(OrderSequenceType which) const override;
    virtual quint64 bidVolume(OrderSequenceType which) const override;
    virtual double askPrice(OrderSequenceType which) const override;
    virtual quint64 askVolume(OrderSequenceType which) const override;
    virtual qint32 date() const override; // YYYYMMDD
    virtual qint32 day() const override;
    virtual qint32 hour() const override;
    virtual qint32 minute() const override;
    virtual qint32 second() const override;
    virtual qint32 millisecond() const override;
    virtual quint64 msecsSinceEpoch() const override;
private:
    SinaTickInfoPrivate *d;
};

class SinaTradeInfo {
public:
    virtual ~SinaTradeInfo(){};
};

class SinaOrderInfo {
public:
    virtual ~ SinaOrderInfo(){};
};

class SinaAccountInfo {
public:
    virtual ~SinaAccountInfo(){};
};

class SinaPoisitionInfo {
public:
    virtual ~SinaPoisitionInfo(){};
};

class SinaLogInfo {
public:
    virtual ~SinaLogInfo(){};
};

class SinaContractInfo {
public:
    virtual ~SinaContractInfo(){};
};

class SinaOrderRequest {
public:
    virtual ~ SinaOrderRequest(){};
};

} // namespace oz
#endif // OZ_SINA_DATATYPE_H
