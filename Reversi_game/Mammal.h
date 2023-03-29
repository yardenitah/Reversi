#ifndef REVERSI_GAME_MAMMAL_H
#define REVERSI_GAME_MAMMAL_H
#include"Player.h"

class Mammal : public Player {
public:
    Mammal(string password, string userName, string name): Player(password, userName, name){}
    virtual void kindToFp();
    virtual void printData() = 0;
//    virtual Mammal* kindOfPlayer(string type);
};

#endif //REVERSI_GAME_MAMMAL_H