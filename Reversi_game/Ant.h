#ifndef REVERSI_GAME_ANT_H
#define REVERSI_GAME_ANT_H
#include "Bug.h"


class Ant:public Bug{
public:
    Ant(string password, string userName, string name): Bug(password, userName, name){}
    virtual void kindFp();
    virtual void printData();
};


#endif //REVERSI_GAME_ANT_H
