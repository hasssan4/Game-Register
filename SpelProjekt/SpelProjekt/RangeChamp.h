#ifndef RangeChamp_h
#define RangeChamp_h

#include "Champion.h"


class RangeChamp : public Champion
{
private:
    string rangeAbility;
public:
    RangeChamp(string champName = "?", string typeOfChamp = "?", string rangeAbility = "?");
    virtual~RangeChamp();
    virtual string toStringSpecific()const;
    string getRangeAbility()const;

};

#endif // RangeChamp_h
