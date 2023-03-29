#ifndef REVERSI_GAME_SHARK_H
#define REVERSI_GAME_SHARK_H
#include "Fish.h"


class Shark: public Fish{
public:
    Shark(string password, string userName, string name): Fish(password, userName, name){}
    virtual void kindFp();
    virtual void printData();
};


#endif //REVERSI_GAME_SHARK_H
