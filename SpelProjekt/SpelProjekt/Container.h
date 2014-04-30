#ifndef Container_h
#define Container_h

#include "Team.h"
#include"GameMode.h"

class GameMode;

class Container
{

 public:

    Container(int capacity = 4);
    Container(const Container &origObj);
    virtual~Container();

    int getNrOfTeams()const;
    void addTeam(string teamName);
    //void addGameMode(string typeOfMode);
    string toString(string what)const;
    void operator=(const Container &origObj);
    //Team *getTeam(int index)const;
    Team *GetTeam(string teamName)const;
    Team *GetTeamByPlayerName(string playerName)const;
    Team *GetTeamByIndex(int index) const;
    int removeTeam(string teamName);
    void saveToFile();
    void readFromFile();


 private:
    Team **teams;
    int nrOfTeams;
    int capacity;



};
#endif // Container_h
