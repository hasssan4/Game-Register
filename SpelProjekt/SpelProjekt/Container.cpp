#include "Container.h"
#include "RangeChamp.h"
#include <fstream>

Container::Container(int capacity)
{
    this->nrOfTeams = 0;
    this->capacity = capacity;
    this->teams = new Team*[this->capacity];
    for(int i = 0;i<this->capacity;i++)
    {
        this->teams[i] = nullptr;
    }
}

int Container::getNrOfTeams()const
{
    return this->nrOfTeams;
}

//Team *Container::getTeam(int index)const
//{
//    return this->teams[index];
//}

Team *Container::GetTeam(string teamName)const
{
    //string TeamName = "";
    for(int i = 0; i<this->getNrOfTeams(); i++)
    {
        if(teamName == this->teams[i]->getTeamName())
        {
            return teams[i];
        }
    }
    return nullptr;
}
Team *Container::GetTeamByIndex(int index)const
{
    return teams[index];
}

Container::~Container()
{
    for(int i = 0;i<nrOfTeams;i++)
    {
        delete teams[i];
    }
    delete[]teams;
}

Container::Container(const Container &origObj)
{
    this->capacity = origObj.capacity;
    this->nrOfTeams = origObj.nrOfTeams;
    this->teams = new Team*[origObj.capacity];

    for (int i = 0; i < origObj.nrOfTeams; i++)
    {
        this->teams[i] = new Team(*origObj.teams[i]);
    }
    for (int i = nrOfTeams; i < capacity;i++)
    {
        this->teams[i] = nullptr;
    }
}


void Container::operator =(const Container &origObj)
{
    if(this != &origObj)
    {
        for(int i = 0;i<nrOfTeams;i++)
        {
            delete teams[i];
        }
        delete[]teams;

        this->capacity = origObj.capacity;
        this->nrOfTeams = origObj.nrOfTeams;
        this->teams = new Team*[origObj.capacity];
        for(int i = 0; i<origObj.nrOfTeams; i++)
        {
            this->teams[i] = new Team(*origObj.teams[i]);
        }
        for(int i = nrOfTeams; i<capacity; i++)
        {
            this->teams[i] = nullptr;

        }
    }
}

void Container::addTeam(string teamName)
{
    if (this->nrOfTeams == this->capacity) //Expandera array
    {
        Team **temp;
        this->capacity += 5;
        temp = new Team *[this->capacity];
        for (int i = 0; i<nrOfTeams; i++)
        {
            temp[i] = teams[i];
        }

        delete[]teams;
        teams = temp;

        for (int i = nrOfTeams; i<this->capacity; i++)
        {
            teams[i] = nullptr;
        }
    }

    this->teams[this->nrOfTeams++] = new Team(teamName); //addar nytt lag till teams.
}

string Container::toString(string what)const
{
    string result;
    if (what == "All" || what == "all")
    {
        for(int i = 0; i < this->nrOfTeams; i++)
        {
             result += this->teams[i]->teamString() + "\n";
        }
    }
    result + "\n";
    return result;
}

int Container::removeTeam(string teamName)
{
    bool removedTeam= false;
        for(int i = 0; i<nrOfTeams; i++)
        {
            if(teamName == this->teams[i]->getTeamName())
            {
                delete this->teams[i];
                teams[i] = nullptr;
                this->nrOfTeams--;

                if (teams[i] != teams[nrOfTeams])
                {
                    teams[i] = teams[nrOfTeams];
                    teams[nrOfTeams] = nullptr;
                }
                removedTeam = true;
            }
        }
        if(removedTeam == false)
        {
            return 0;
        }
        else
        {
            return 1;
        }
}

Team* Container::GetTeamByPlayerName(string playerName)const
{
    for(int i = 0; i < nrOfTeams; i++)
    {
        bool playerFound = teams[i]->findPlayer(playerName);

        if(playerFound == true)
        {
            return teams[i];
        }
    }

    return nullptr;
}

void Container::saveToFile()
{
    ofstream out;

    out.open("Teams.txt");
    if(out.is_open())
    {
        out << this->capacity << endl;
        out << this->nrOfTeams << endl;
        for(int i = 0; i<this->nrOfTeams; i++)
        {
            out << this->teams[i]->getTeamName() << endl;
            out << this->teams[i]->getNrOfPlayers() << endl;

           for(int k = 0; k < this->teams[i]->getNrOfPlayers(); k++)
           {
                out << this->teams[i]->getPlayerByIndex(k)->getPlayerName() << endl;
                out << this->teams[i]->getPlayerByIndex(k)->getLevel() << endl;
                out << this->teams[i]->getPlayerByIndex(k)->getRank() << endl;
                out << this->teams[i]->getPlayerByIndex(k)->getNrOfChamps() << endl;

                for(int j = 0; j<this->teams[i]->getPlayerByIndex(k)->getNrOfChamps(); j++)
                {
                     out << this->teams[i]->getPlayerByIndex(k)->getChampByIndex(j)->getChampName() << endl;
                     out << this->teams[i]->getPlayerByIndex(k)->getChampByIndex(j)->getTypeOfChamp() << endl;
                     out << this->teams[i]->getPlayerByIndex(k)->getChampByIndex(j)->getChamp() << endl;
                     if(this->teams[i]->getPlayerByIndex(k)->getChampByIndex(j)->getChamp() == "Range")
                     {
                         RangeChamp *range = dynamic_cast<RangeChamp *>(this->GetTeam(teams[i]->getTeamName())->getPlayerByIndex(k)->getChampByIndex(j));
                         if(range != nullptr)
                         {
                             out << range->getRangeAbility() << endl;
                         }
                         delete range;
                     }

                     else if(this->teams[i]->getPlayerByIndex(k)->getChampByIndex(j)->getChamp() == "Meele")
                     {
                            MeeleChamp *meele = dynamic_cast<MeeleChamp *>(this->GetTeam(teams[i]->getTeamName())->getPlayerByIndex(k)->getChampByIndex(j));
                            if(meele != nullptr)
                            {
                                out << meele->getMeeleAbility() << endl;
                            }
                            delete meele;
                     }
                 }

           }
        }
    }

    out.close();
}

void Container::readFromFile()
{
    ifstream in;

    int cap;
    int NrOfTeams;
    string teamName;
    int nrOfPlayers;
    string playerName = "?";
    int lvl = 0;
    string rank = "?";
    int nrOfChamps = 0;
    string champName = "?";
    string typeOfChamp = "?";
    string champ = "?";
    string meeleAbility = "?";
    string rangeAbility = "?";

    in.open("Teams.txt");
    if(in.is_open())
    {
        in >> cap;
        in >> NrOfTeams;

        //in.ignore();
        for(int i = 0; i<NrOfTeams; i++)
        {
           in.ignore();
           getline(in,teamName);
           in >> nrOfPlayers;
           this->addTeam(teamName);


           for(int k = 0; k < nrOfPlayers; k++)
           {
               in.ignore();
               getline(in, playerName);
               in >> lvl;              
               in >> rank;
               in >> nrOfChamps;
               teams[i]->addPlayer(playerName, lvl, rank);


               for(int j = 0; j<nrOfChamps; j++)
               {                  
                   in >> champName;
                   in >> typeOfChamp;
                   in >> champ;

                   if(champ == "Range")
                   {
                       in >> rangeAbility;
                       teams[i]->getPlayerByIndex(k)->addRangeChamp(champName, typeOfChamp, rangeAbility );
                   }
                   else if(champ == "Meele")
                   {
                       in >> meeleAbility;
                       teams[i]->getPlayerByIndex(k)->addMeeleChamp(champName, typeOfChamp, meeleAbility);
                   }

                }
            }
        }
       in.close();
    }   

}
