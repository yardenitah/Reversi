#ifndef REVERSI_GAME_BARRACUDA_H
#define REVERSI_GAME_BARRACUDA_H
#include "Fish.h"


class Barracuda:public Fish {
public:
    Barracuda(string password, string userName, string name): Fish(password, userName, name){}
    virtual void kindFp();
    virtual void printData();
};


#endif //REVERSI_GAME_BARRACUDA_H
