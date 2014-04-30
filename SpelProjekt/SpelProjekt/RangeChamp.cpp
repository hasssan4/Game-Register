#include "RangeChamp.h"

//Spelaren äger har ett antal champions som han kan välja att spela med
RangeChamp::RangeChamp(string champName,string typeOfChamp, string rangeAbility) :Champion(champName, typeOfChamp)
{
    this->rangeAbility = rangeAbility;
    this->champ = "Range";
}

RangeChamp::~RangeChamp()
{

}

string RangeChamp::toStringSpecific() const
{
    string result = "";
    result = "Range ability: " + rangeAbility + "\n";
    return result;
}

string RangeChamp::getRangeAbility()const
{
    return this->rangeAbility;
}
