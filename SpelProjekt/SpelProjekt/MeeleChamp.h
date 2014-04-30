#ifndef MeeleChamp_h
#define MeeleChamp_h

#include "Champion.h"


class MeeleChamp :public Champion
{
private:
    string meeleAbility;
public:
    MeeleChamp(string champName = "?", string typeOfChamp = "?", string meeleAbility = "?");
    virtual~MeeleChamp();
    virtual string toStringSpecific()const;
    string getMeeleAbility()const;

};

#endif // MeeleChamp_h
