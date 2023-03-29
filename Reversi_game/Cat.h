#ifndef REVERSI_GAME_CAT_H
#define REVERSI_GAME_CAT_H
#include "Mammal.h"


class Cat : public Mammal{
public:
    Cat(string password, string userName, string name): Mammal(password, userName, name){}
    virtual void kindFp();
    virtual void printData();
    void printCat();

private:
};


#endif //REVERSI_GAME_CAT_H
