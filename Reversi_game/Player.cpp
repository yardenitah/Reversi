#include "Player.h"

Player::Player(string password, string userName, string name) {
    this->password = password;
    this->userName = userName;
    this->name = name;
    this->points = 0;
    this-> win = false;
    nameFP = "dataOfAllPlayer1.txt";
}

Player &Player::operator=(const Player &other) {
    this->userName = other.userName;
    this->password = other.password;
    this->name = other.name;
    this->points = other.points;
    return *this;
}

Player::Player(const Player &other) {
    this->userName = other.userName;
    this->password = other.password;
    this->name = other.name;
    this->points = other.points;
}

bool Player::operator==(Player *other) const {
    if (this->userName == other->userName && this->password == other->password && this->name == other->name &&
        this->points == other->points) {
        return true;
    }
    return false;
}

bool Player::checkUsername(string username) {
    if (this->userName == username)
        return true;
    return false;
}

void Player::inToFp() const {
    fstream FP;
    FP.open(nameFP, ios::app);
    if (FP.is_open())
        FP << "username:" << userName << " password:" << password << " name:" << name << " points:" << points << endl
           << endl;
}

void Player::setSymbol(char symbol) {
    if (symbol == 'x' || symbol == 'o') {
        this->symbolPlayer = symbol;
    } else cout << "invalid Symbol" << endl;
}

void Player::setWin(bool x) {
    this->win = x;
}

bool Player::getWin() {
    return win;
}

void Player::printPlayer() const {
    cout<< name;
}
