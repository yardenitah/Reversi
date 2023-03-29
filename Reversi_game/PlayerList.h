#ifndef REVERSI_GAME_PLAYERLIST_H
#define REVERSI_GAME_PLAYERLIST_H
#include "Player.h"
#include "Dog.h"
#include "Cat.h"
#include "Dolphin.h"
#include "Grasshopper.h"
#include "Shark.h"
#include "Wasp.h"
#include "Barracuda.h"
#include "Ant.h"
#include <ctime>

class PlayerList {
public:
    PlayerList(); //default constructor
    PlayerList(const PlayerList& other);  // copy constructor
    ~PlayerList();  //destructor
    bool operator&&(Player* player) const;
    bool operator+=(Player* player);
    bool operator-=(Player* player);
    bool insertPlayer(string name, string password, string username, PlayerList &list);
    bool addMammal(string name, string password, string username, PlayerList &list, Mammal *mammal);
    bool addFish(string name, string password, string username, PlayerList &list, Fish *fish);
    bool addBug(string name, string password, string username, PlayerList &list, Bug *bug);
    void ifUsernameExist(string username);
    string typeOfPlayer();
    int getsize()const {return this->size;}
    int randAll();
    bool iFleaguePossible() ;
    void setSize(int size);
    Player** getList();
    Player **list;


private:
    int size;
};

void menu();

#endif //REVERSI_GAME_PLAYERLIST_H







