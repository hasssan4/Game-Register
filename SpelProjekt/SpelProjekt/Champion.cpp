#include "Champion.h"

//Spelaren  har ett antal champions som han kan välja att spela med
Champion::Champion(string champName, string typeOfChamp, string champ)
{
    this->champName = champName;
    this->typeOfChamp = typeOfChamp;
    this->champ = champ;
}

Champion::~Champion()
{
}

string Champion::toString() const
{
    string result;
    result = "Champion name: " + champName + "\n" + "Type of champion: " + typeOfChamp + "\n" + toStringSpecific() + "\n";
    return result;
}

string Champion::getChampName()const
{
    return this->champName;
}

string Champion::getTypeOfChamp()const
{
    return this->typeOfChamp;
}

string Champion::getChamp()const
{
    return this->champ;
}
