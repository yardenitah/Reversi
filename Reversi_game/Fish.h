#ifndef REVERSI_GAME_FISH_H
#define REVERSI_GAME_FISH_H
#include "Player.h"


class Fish :public Player{
public:
    Fish(string password, string userName, string name): Player(password, userName, name){}
    virtual void kindToFp();
    virtual void printData() = 0;
};


#endif //REVERSI_GAME_FISH_H
