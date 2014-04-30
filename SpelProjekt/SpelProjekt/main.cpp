#include "Player.h"
#include "MeeleChamp.h"
#include "RangeChamp.h"
#include "Container.h"
#include "Team.h"
#include "GameMode.h"
#include<iostream>

int main()
{
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Container *container = new Container();
	string load;
	cout << "Do you wish to load ? (yes/no)";
	cin >> load;
	if (load == "yes")
	{
		container->readFromFile();
	}
	Team *team1 = new Team("champs");
	cout << endl;
	container->addTeam("Kings");
	
	team1->addPlayer("Mohamed", 30, "Gold5");
	team1->getPlayer("Mohamed")->addMeeleChamp("Udyr", "Tank/fighter", "Tigerstance");
	cout << team1->teamString() << endl;
	cout << team1->playersStrings() << endl;
	cout << team1->getPlayer("Mohamed")->champString() << endl;
	
	cout << "----------------------------------------------................................---------------------------------" << endl;
	Player *p1 = new Player("Hasse", 10, "Silver3");
	//cout << p1->playerString();

	cout << "-------------\n";
	//p1->addRangeChamp("test", "noob", "Bullets");
	Player *p2 = new Player("Murre", 15, "Silver5");

	p2->addMeeleChamp("Udyr", "Tank/fighter", "Tigerstance");
	//cout<<p2->champString() << "------------------------------"<< endl;

	RangeChamp champ =  RangeChamp("Lucian", "Marksman", "Ligtbringer");
	//cout << champ.toString() << "-----------------------------" << endl;

	

	
	
	string save;
	cout << "Do you wish to save ? (yes/no)";
	cin >> save;
	if (save == "yes")
	{
		container->saveToFile();
	}
	
	delete team1;
	delete container;
	delete p1;
	delete p2;
	cout<<"\n\n\n\n";
	system("pause");
	return 0;
}