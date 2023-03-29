#ifndef REVERSI_GAME_DOG_H
#define REVERSI_GAME_DOG_H
#include "Mammal.h"

class Dog :public Mammal{
public:
    Dog(string password, string userName, string name): Mammal(password, userName, name){}
    virtual void kindFp();
    virtual void printData();
    void printDog();
};

#endif //REVERSI_GAME_DOG_H
