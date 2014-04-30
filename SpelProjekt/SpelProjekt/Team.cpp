#include "Team.h"
#include<sstream>

Team::Team(string teamName)
{
    this->teamName = teamName;
    this->nrOfPlayers = 0;
    this->capacity = 5;
    this->players = new Player*[capacity];


    for (int i = 0; i < capacity; i++)
    {
        this->players[i] = nullptr;
    }
}

Player *Team::getPlayerByIndex(int index) const
{
    return players[index];
}

Player *Team::getPlayer(string playerName)const
{
    for(int i = 0; i < nrOfPlayers; i++)
    {
        if(playerName == players[i]->getPlayerName())
        {
            return this->players[i];
        }
    }

    return nullptr;
}

void Team::addPlayer(string name, int level, string rank)
{
    if (this->nrOfPlayers == this->capacity)
    {
        this->capacity += 5;
        Player **temp = new Player*[capacity];

        for (int i = 0; i < nrOfPlayers; i++)
        {
            temp[i] = players[i];
        }

        delete[] players;
        players = temp;

        for (int i = nrOfPlayers; i < capacity; i++)
        {
            players[i] = nullptr;
        }
    }
    this->players[this->nrOfPlayers++] = new Player(name, level, rank);
}

Team::~Team()
{
    for (int i = 0; i < nrOfPlayers; i++)
    {
        delete players[i];
    }
    delete[]players;
}


int Team::getNrOfPlayers() const
{
    return nrOfPlayers;
}

string Team::getTeamName()const
{
    return this->teamName;
}

//string Team::GetTeamName()const
//{
//    for(int i = 0; i<this->nrOfPlayers; i++)
//    {
//       // return this->players[i];
//    }
//}

string Team::teamString()const
{
    stringstream result;
    result << "Lag namn: " << teamName  << "\n" << "Antal spelare: " << nrOfPlayers << endl;
    return result.str();

}

 string Team::playersStrings()const //
{

    string result = "";
    for (int i = 0; i < this->nrOfPlayers;i++)
    {
         result += this->players[i]->playerString();
    }
    result + "\n";
    return result;
}

 int Team::removePlayer(string playerName)
{
     bool removedPlayer = false;
         for(int i = 0; i<nrOfPlayers; i++)
         {
             if(playerName == this->players[i]->getPlayerName())
             {
                 delete this->players[i];
                 players[i] = nullptr;
                 this->nrOfPlayers--;

                 if (players[i] != players[nrOfPlayers])
                 {
                     players[i] = players[nrOfPlayers];
                     players[nrOfPlayers] = nullptr;
                 }
                 removedPlayer = true;
             }
         }
         if(removedPlayer == false)
         {
             return 0;
         }
         else
         {
             return 1;
         }
}

 bool Team::findPlayer(string playerName)const
 {
     for(int i = 0; i < nrOfPlayers; i++)
     {
         if(players[i]->getPlayerName() == playerName)
         {
             return true;
         }
     }

     return false;
 }

 string Team::champsToString()const
 {
     string str = "";

     for(int i = 0;i < nrOfPlayers; i++)
     {
         str += players[i]->champString() + "\n";
     }

     return str;
 }

 Player **Team::getPlayers() const
 {
     return players;
 }
