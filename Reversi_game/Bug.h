#ifndef REVERSI_GAME_BUG_H
#define REVERSI_GAME_BUG_H
#include "Player.h"


class Bug: public Player{
public:
    Bug(string password, string userName, string name): Player(password, userName, name){}
    virtual void kindToFp();
    virtual void printData() = 0;
};


#endif //REVERSI_GAME_BUG_H
