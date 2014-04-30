#include "Player.h"
#include<sstream>
#include"Team.h"
//Spelaren ett antal champions som han kan välja att spela med
//Ska inte gå att ta bort champion eftersom spelaren äger(har köpt) champions. I spelet LOL t.ex. så kan man inte sälja eller ta bort champ.

Player::Player(string name, int level, string rank)
{
    this->name = name;           //Unikt spelar namn
    this->level = level;
    this->rank = rank;
    this->capacity = 5;
    this->nrOfChampions = 0;

    this->champions = new Champion*[capacity];
    for (int i = 0; i < capacity; i++)
    {
        champions[i] = nullptr;
    }
}

//Player *Player::getPlayer(string playerName) const
//{
//}
Champion *Player::getChampByIndex(int index) const
{
    return champions[index];
}
string Player::getPlayerName()const
{
    return this->name;
}
int Player::getLevel()const
{
    return this->level;
}

string Player::getRank()const
{
    return this->rank;
}


int Player::getNrOfChamps()const
{
    return this->nrOfChampions;
}

void Player::addRangeChamp(string champName, string typeOfChamp, string rangeAbility)
{
    this->expand();
    champions[nrOfChampions++] = new RangeChamp(champName, typeOfChamp, rangeAbility);
}

void Player::addMeeleChamp(string champName, string typeOfChamp, string meeleAbility)
{
    this->expand();
    champions[nrOfChampions++] = new MeeleChamp(champName, typeOfChamp, meeleAbility);
}

Player::~Player()
{
    this->freeMemory();
}

string Player::playerString() const
{
    stringstream result;
    result << "Name: " << name << "\n" << "Level: " << level << "\n" << "Rank: " << rank << "\n" << endl;
    return result.str();
}

string Player::champString()const
{
    string result;
    for (int i = 0; i < this->nrOfChampions; i++)
    {
        result += champions[i]->toString();
    }
    result + "\n";
    return result;
}

void Player::freeMemory()
{
    for (int i = 0; i < nrOfChampions; i++)
    {
        delete this->champions[i];
    }

    delete[]champions;
}

void Player::expand()
{
    if (nrOfChampions == capacity)
    {
        capacity += 5;
        Champion **temp = new Champion*[capacity];
        for (int i = 0; i < nrOfChampions; i++)
        {
            temp[i] = champions[i];
        }
        delete[]champions;
        champions = temp;
        for (int i = nrOfChampions; i < capacity; i++)
        {
            champions[i] = nullptr;
        }
    }
}


