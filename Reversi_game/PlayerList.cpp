#include "PlayerList.h"

PlayerList::PlayerList() {
    list = nullptr;
    size = 0;
}

PlayerList::~PlayerList() {
    delete[] list;
}

bool PlayerList::operator&&(Player* player) const{
    fstream FP;
    string temp;
    string FPname = player->getNameFP();
    FP.open(FPname, ios::in);
    if (FP.is_open()) {
        while (getline(FP, temp)) {
            if (temp.find(player->getUserName()) != std::string::npos) {
                FP.close();
                return true;
            }
        }
    }
    FP.close();
    return false;
}

bool PlayerList::operator+=(Player *player) {
    if (size == 0) {
        size++;
        list = new Player *[size];
        list[size - 1] = player;
        return true;
    }
    if (!operator&&(player)) {
        Player **temp;
        temp = new Player *[size];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        size++;
        list = new Player *[size];
        for (int i = 0; i < size-1; i++) {
            list[i] = temp[i];
        }
        list[size-1] = player;
        delete temp;
        return true;
    }
    return false;
}

bool PlayerList::operator-=(Player *player) {
    if (size == 1 && operator&&(player)) {
        list = nullptr;
        size = 0;
        return true;
    }
    if (operator&&(player)) {
        Player **temp;
        temp = new Player *[size];
        for (int i = 0; i < size; i++) {
            temp[i] = list[i];
        }
        delete[] list;
        size--;
        list = new Player *[size];
        int j = 0;
        for (int i = 0; i < size+1; i++) {
            if (temp[i] == player) {
                continue;
            } else {
                list[j] = temp[i];
                j++;
            }
        }
        delete[] temp;
        return true;
    }
    return false;
}

PlayerList::PlayerList(const PlayerList &other) {
    this->size = other.size;
    this->list = new Player * [size];
    this->list = other.list;
}

bool PlayerList::addMammal(string name, string password, string username, PlayerList &list, Mammal *mammal) {
    bool stat;
    string x;

    cout << "1. Dog" << endl << "2. Cat" << endl << "3. Dolphin" << endl;
    do {
        cin >> x;
        if (x == "1") {
            Dog dog(password, username, name);
            mammal = &dog;
            stat = (list += mammal);
            if (stat) {
                dog.inToFp();
                return true;
            } else return false;
        }
        if (x == "2") {
            Cat cat(password, username, name);
            mammal = &cat;
            stat = (list += mammal);
            if (stat) {
                cat.inToFp();
                return true;
            } else return false;
        }
        if (x == "3") {
            Dolphin dolphin(password, username, name);
            mammal = &dolphin;
            stat = (list += mammal);
            if (stat) {
                dolphin.inToFp();
                return true;
            } else return false;
        } else if (x != "1" && x != "2" && x != "3")
            cout << endl << "invalid input try again : ";
    } while (x != "1" && x != "2" && x != "3");
}

bool PlayerList::addBug(string name, string password, string username, PlayerList &list, Bug *bug) {
    bool stat;
    string x;

    cout << "1. Ant" << endl << "2. Grasshopper" << endl << "3. Wasp" << endl;
    do {
        cin >> x;
        if (x == "1") {
            Ant ant(password, username, name);
            bug = &ant;
            stat = (list += bug);
            if (stat) {
                ant.inToFp();
                return true;
            } else return false;
        }
        if (x == "2") {
            Grasshopper grasshopper(password, username, name);
            bug = &grasshopper;
            stat = (list += bug);
            if (stat) {
                grasshopper.inToFp();
                return true;
            } else return false;
        }
        if (x == "3") {
            Wasp wasp(password, username, name);
            bug = &wasp;
            stat = (list += bug);
            if (stat) {
                wasp.inToFp();
                return true;
            } else return false;
        } else if (x != "1" && x != "2" && x != "3")
            cout << endl << "invalid input try again : ";

    } while (x != "1" && x != "2" && x != "3");
}


bool PlayerList::addFish(string name, string password, string username, PlayerList &list, Fish *fish) {
    bool stat;
    string x;
    cout << "1. Shark" << endl << "2. Barracuda" << endl;
    do {
        cin >> x;
        if (x == "1") {
            Shark shark(password, username, name);
            fish = &shark;
            stat = (list += fish);
            if (stat) {
                shark.inToFp();
                return true;
            } else return false;
        }
        if (x == "2") {
            Barracuda barracuda(password, username, name);
            fish = &barracuda;
            stat = (list += fish);
            if (stat) {
                barracuda.inToFp();
                return true;
            } else return false;
        } else if (x != "1" && x != "2")
            cout << endl << "invalid input try again : ";
    } while (x != "1" && x != "2");
}

bool PlayerList::insertPlayer(string name, string password, string username, PlayerList &list) {
    string x;
    cout << "1. Mammal" << endl << "2. Fish" << endl << "3. Bug" << endl;
    do {
        cin >> x;
        if (x == "1") {
            Mammal *mammal = nullptr;
            if (addMammal(name, password, username, list, mammal)) return true;
            else return false;
        }
        if (x == "2") {
            Fish *fish = nullptr;
            if (addFish(name, password, username, list, fish)) return true;
            else return false;
        }
        if (x == "3") {
            Bug *bug = nullptr;
            if (addBug(name, password, username, list, bug)) return true;
            else return false;
        }
        else if (x != "1" && x != "2" && x != "3")
            cout << endl << "invalid input try again : ";

    } while (x != "1" && x != "2" && x != "3");
}

bool PlayerList::iFleaguePossible() {
    int couter = 0;
    fstream FP;
    string temp;
    FP.open("dataOfAllPlayer1.txt", ios::in);
    if (FP.is_open()) {
        while (getline(FP, temp)) {
            if (temp.find("username:") != std::string::npos) {
                couter++;
            }
        }
    }
    FP.close();
    if (couter >= 2 )
    {
        if (couter % 2 ==0){
            return true;
        }
    }
    cout<<"The number of players does not correspond to the existence of a league"<<endl;
    return false;
}

void PlayerList::setSize(int size) {
    this->size = size;
}

Player **PlayerList::getList() {
    return this->list;
}



