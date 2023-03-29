#ifndef REVERSI_GAME_DOLPHIN_H
#define REVERSI_GAME_DOLPHIN_H
#include "Mammal.h"

class Dolphin : public Mammal {
public:
    Dolphin(string password, string userName, string name) : Mammal(password, userName, name){}
    virtual void kindFp();
    virtual void printData();
};

#endif // REVERSI_GAME_DOLPHIN_H
