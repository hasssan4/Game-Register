#include "MeeleChamp.h"
//Spelaren  har ett antal champions som han kan välja att spela med

MeeleChamp::MeeleChamp(string champName, string typeOfChamp, string meeleAbility) :Champion(champName, typeOfChamp)
{
    this->meeleAbility = meeleAbility;
    this->champ = "Meele";
}

MeeleChamp::~MeeleChamp()
{

}

string MeeleChamp::toStringSpecific() const
{
    string result = "";
    result = "Meele ability: " + meeleAbility + "\n";
    return result;
}

string MeeleChamp::getMeeleAbility()const
{
    return this->meeleAbility;
}
