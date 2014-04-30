#ifndef Team_h
#define Team_h

class GameMode;
class Player;
#include "Player.h"
#include<string>
using namespace std;

class Team
{
 public:

    Team(string teamName = "?");
    virtual ~Team();
    int getNrOfPlayers() const;
    string teamString()const;
    string playersStrings()const;
    void addPlayer(string name, int level, string rank);
    string getTeamName()const;
    Player *getPlayer(string playerName)const;
    bool findPlayer(string playerName)const;
//    string GetTeamName() const;
    int removePlayer(string playerName);
    string champsToString()const;
    Player **getPlayers()const;
    Player *getPlayerByIndex(int index)const;

 private:
     string teamName;
     int nrOfPlayers;
     int capacity;
     Player **players;


};

#endif // Team_h
