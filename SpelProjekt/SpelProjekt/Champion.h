#ifndef Champion_h
#define Champion_h

#include <string>
using namespace std;

class Champion
{
public:

private:
    string champName;
    string typeOfChamp;
protected:
    string champ;
public:
    Champion(string champName = "?", string typeOfChamp = "?", string champ = "");
    string toString() const;
    virtual ~Champion();
    virtual string toStringSpecific()const = 0;
    string getChampName()const;
    string getTypeOfChamp()const;
    string getChamp()const;
};

#endif // Champion_h
