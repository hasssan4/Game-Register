#include "GameMode.h"

GameMode::GameMode(string typeOfMode)
{
    this->typeOfMode = typeOfMode;           //5 vs 5, 3 vs 3, ARAM 5 vs 5, 3 vs AI, 5 vs  AI,Custom mode

}

GameMode::~GameMode()
{

}

string GameMode::getTypeOfMode()const
{
    return this->typeOfMode;
}
