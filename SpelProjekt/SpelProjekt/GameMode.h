#ifndef GameMode_h
#define GameMode_h

class Team;
#include<string>
using namespace std;

class GameMode
{
 public:

    GameMode(string typeOfMode);
    ~GameMode();

    string toString()const;
    string getTypeOfMode()const;


 private:
    string typeOfMode;


};

#endif // GameMode_h
