#ifndef Player_h
#define Player_h

#include<string>
#include"RangeChamp.h"
#include"MeeleChamp.h"
#include"Champion.h"

using namespace std;

class Player
{
public:
    Player(string name = "?", int level = 0, string rank = "?");
    virtual~Player();
    void addRangeChamp(string champName, string typeOfChamp, string rangeAbility);
    void addMeeleChamp(string champName, string typeOfChamp, string meeleAbility);
    int getNrOfChamps()const;
    string playerString()const;
    string champString()const;
    string getPlayerName()const;
    int getLevel()const;
    string getRank()const;
    Champion *getChampByIndex(int index)const;
//    Player *getPlayer(string playerName)const;
    //Ska inte gå att ta bort champion eftersom spelaren äger champions och ska inte kunna ta bort dem.

private:
    string name;       //Unikt spelar namn för varje spelare
    int level;
    string rank;

    Champion **champions; //Spelaren  har ett antal champions som han kan välja att spela med
    int nrOfChampions;
    void expand();
    void freeMemory();
    int capacity;
};

#endif // Player_h
