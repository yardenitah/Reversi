#ifndef REVERSI_GAME_WASP_H
#define REVERSI_GAME_WASP_H
#include "Bug.h"


class Wasp:public Bug{
public:
    Wasp(string password, string userName, string name): Bug(password, userName, name){}
    virtual void kindFp();
    virtual void printData();

};


#endif //REVERSI_GAME_WASP_H
