#include "sinadatatypes.h"
#include <QStringList>
namespace oz {
class SinaTickInfoPrivate {
public:
    void parse(const QString& source);
    QString ticker;
    double averagePrice;
    double lastPrice;
    double preClosePrice;
    double openPrice;
    double closePrice;
    double highPrice;
    double lowPrice;
    quint64 volume;
    double turnover;
    double bidPrice[TickInfo::TenthOrder+1];
    quint64 bidVolume[TickInfo::TenthOrder+1];
    double askPrice[TickInfo::TenthOrder+1];
    quint64 askVolume[TickInfo::TenthOrder+1];
    quint64 datetime; // YYYYmmddHHMMSSsss
//     qint32 date; // YYYYMMDD
//     qint32 day;
//     qint32 hour;
//     qint32 minute;
//     qint32 second;
//     qint32 millisecond;
//     quint64 msecsSinceEpoch;
};

void SinaTickInfoPrivate::parse(const QString& source) {
    QStringList items = source.split(',');
    if (items.count() != 32) { // TODO
        return;
    }
    // 0
    ticker = items.value(0).mid(11, 8);
    // 1
    openPrice = items.value(1).toDouble();
    // 2
    closePrice = items.value(2).toDouble();
    // 3
    lastPrice = items.value(3).toDouble();
    // 4
    highPrice = items.value(4).toDouble();
    // 5
    lowPrice = items.value(5).toDouble();
    // 6
    // bidPrice1
    // 7
    // askPrice1
    // 8
    volume = items.value(8).toULongLong();
    // 9
    turnover = items.value(9).toDouble();
    // 10
    for (int i = 0; i < 5; ++i) {
        bidVolume[i] = items.value(10 + i * 2).toULongLong();
        bidPrice[i] = items.value(10 + i * 2 + 1).toDouble();
    }
    for (int i = 0; i < 5; ++i) {
        askVolume[i] = items.value(20 + i * 2).toULongLong();
        askPrice[i] = items.value(20 + i * 2 + 1).toDouble();
    }
    // 30
    auto day = items.value(30);
    auto time = items.value(30);
    day.replace('-', "");
    time.replace(':', "");
    day += time + "000";
    datetime = day.toULongLong();
}


SinaTickInfo::SinaTickInfo(const QString& source) : d(new SinaTickInfoPrivate) {
    d->parse(source);
}
SinaTickInfo::~SinaTickInfo () {
    delete d;
}

QString SinaTickInfo::ticker() const {
    return d->ticker;
}

double SinaTickInfo::averagePrice() const {
    return d->averagePrice;
}

double SinaTickInfo::lastPrice() const {
    return d->lastPrice;
}

double SinaTickInfo::preClosePrice() const {
    return d->preClosePrice;
}

double SinaTickInfo::openPrice() const {
    return d->openPrice;
}

double SinaTickInfo::closePrice() const {
    return d->closePrice;
}

double SinaTickInfo::highPrice() const {
    return d->highPrice;
}

double SinaTickInfo::lowPrice() const {
    return d->lowPrice;
}

quint64 SinaTickInfo::volume() const {
    return d->volume;
}

double SinaTickInfo::turnover() const {
    return d->turnover;
}

double SinaTickInfo::bidPrice(OrderSequenceType which) const {
    return d->bidPrice[which];
}

quint64 SinaTickInfo::bidVolume(OrderSequenceType which) const {
    return d->bidVolume[which];
}

double SinaTickInfo::askPrice(OrderSequenceType which) const {
    return d->askPrice[which];
}

quint64 SinaTickInfo::askVolume(OrderSequenceType which) const {
    return d->askVolume[which];
}

// TODO
qint32 SinaTickInfo::date() const {
    return 0;
} // YYYYMMDD
qint32 SinaTickInfo::day() const {
    return 0;
}

qint32 SinaTickInfo::hour() const {
    return 0;
}

qint32 SinaTickInfo::minute() const {
    return 0;
}

qint32 SinaTickInfo::second() const {
    return 0;
}

qint32 SinaTickInfo::millisecond() const {
    return 0;
}

quint64 SinaTickInfo::msecsSinceEpoch() const {
    return 0;
}

}
