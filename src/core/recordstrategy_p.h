#ifndef RECORDSTRATEGYPRIVATE_H
#define RECORDSTRATEGYPRIVATE_H

namespace oz {

class RecordStrategyPrivate
{
public:
    RecordStrategyPrivate(RecordStrategy* q);
    virtual ~RecordStrategyPrivate();

private:
    class RecordStrategy* const q;
};
}

#endif // RECORDSTRATEGYPRIVATE_H
