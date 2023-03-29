#ifndef REVERSI_GAME_GRASSHOPPER_H
#define REVERSI_GAME_GRASSHOPPER_H
#include "Bug.h"

class Grasshopper: public Bug{
public:
    Grasshopper(string password, string userName, string name): Bug(password, userName, name){}
    virtual void kindFp();
    virtual void printData();

};

#endif //REVERSI_GAME_GRASSHOPPER_H
