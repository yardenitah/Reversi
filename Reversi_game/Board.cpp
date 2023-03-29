#include "Board.h"
#include <iostream>
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#define infinity 1000;

//
//void Board::play_computer() {
//    int index1, index2;
//    string* temp = new string [size];
//    bool m;
//    while (true){
//        // x play.
//        cout<<"X  move (enter  row and column indexes) : ";
//        do {
//            cin>>index1>>index2;
//            temp = newString(temp, str);
//            m = correctMove(temp, index1, index2, 'x');
//            if (!m) cout <<endl << "invalid move try again : ";
//        } while (!m);
//        newMove(this->str, index1, index2, 'x');
//        flip(this->str, 'x', index1, index2);
//        print();
//        if(gameOver(temp, 'x')) break;
//
//
//
//        // computer move ( O move ).
//        computerMove(&index1, &index2);
//        newMove(this->str, index1, index2, 'o');
//        flip(this->str, 'o', index1, index2);
//        print();
//        if(gameOver(temp,'o')) break;
//    }
//    delete[] temp;
//}   ////// !!!

int Board::boardEvaluatino(string* board) {

    int maxOp = 0, minOp = 0, op = 0;
    char player = 'x', other = '0';
    if (checkIfPlayerWin(player) || gameOver(board, other)) {
        op = -100;
        return op;
    }
    player = 'o', other = 'x';
    if (checkIfPlayerWin(player) || gameOver(board, other)) {
        op = 100;
        return op;
    }

    return 0;
}

void Board::computerMove(int *index1, int *index2) {  // Uses a copy of the board.
    Move move = miniMax(str, 'o', 2);
    *index1 = move.indexI;
    *index2 = move.indexJ;
}

Board::Move Board::miniMax(string *board, char player, int steps) {
    if (steps == 0) {
        Move move;
        move.evaluation = boardEvaluatino(board);
        return move;
    }
    steps--;

    char nextPlayer = 'o';
    if (player == 'o') nextPlayer = 'x';

    int maxScour = -infinity;
    int minScour = infinity;
    int maxindexI = 0;
    int maxindexJ = 0;
    int minindexI = 0;
    int minindexJ = 0;

    //moves
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != ' ' || !correctMove(board, i, j, player)) continue;

            board[i][j] = player;
            Move move = miniMax(board, nextPlayer, steps);
            if (move.evaluation > maxScour) {
                maxScour = move.evaluation;
                maxindexI = i;
                maxindexJ = j;
            }
            if (move.evaluation < minScour) {
                minScour = move.evaluation;
                minindexI = i;
                minindexJ = j;
            }
            board[i][j] = ' ';
        }
    }
    if (player == 'o') {
        Move move;
        move.evaluation = maxScour;
        move.indexJ = maxindexI;
        move.indexJ = maxindexJ;
        return move;
    } else {
        Move move;
        move.evaluation = minScour;
        move.indexI = minindexI;
        move.indexJ = minindexJ;
        return move;
    }
}

void Board::print() const{
    cout <<endl;
    for (int i = 0; i < size; i++) {
        cout<<" "<<i<<"  ";
    }cout<<endl;
    for (int i = 0; i < size; i++) {
        cout<<"\033[1;42m" << i << "\033[0m";  // green background
        for (int j = 0; j < size; j++) {
            cout << "\033[1;42m ";  // green background
            if (str[i][j] == 'o') {
                cout << "\033[1;30m" << str[i][j] << "\033[0m";  // black color
            } else if (str[i][j] == 'x') {
                cout << "\033[1;31m" << str[i][j] << "\033[0m";  // red color
            } else {
                cout << str[i][j];
            }
            cout << "\033[0m ";  // reset color
            if (j != size-1)
                cout << "\033[1;42m|\033[0m";  // green background
        }
        cout<<endl;
        for (int k = 0; k < size; k++) {
            if (i == size-1)
                break;
            if (k == size-1)
                cout<<"---";
            if (k == 0)
                cout<<" ---|";
            if (k != 0 && k != size-1)
                cout<<"---|";
        }
        cout<<endl;
    }
}

void Board::resetBoard() {
    str = new string[size];
    for (int i = 0; i < this->size; i++) {
        str[i].resize(size);
    }
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (j == this->size /2 && i+j == this->size -1){
                str[i][j] = 'o';
                str[i][j-1] = 'x';
                str[i+1][j] = 'x';
                str[i+1][j-1] = 'o';
            }
            if (str[i][j] != 'x' && str[i][j] != 'o')
                str[i][j] = ' ';
        }
    }
}

void Board::newMove(string* board, int index1, int index2, char player) {
    board[index1][index2] = player;
}

bool Board::fullBoard() const{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (str[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int Board::checkRow(string *board, char player, int index1, int index2) { //
    int tempIndex = -1, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if (index2 + 1 < size && board[index1][index2 + 1] == toReplace) {

        for (int j = index2 + 1; j < size; j++) {
            if (board[index1][j] == ' ') return 0;
            if (board[index1][j] == player) {
                tempIndex = j;
                break;
            }
        }
        if (tempIndex == -1) return 0;

        for (int j = index2 + 1; j < tempIndex; j++) {
            if (board[index1][j] == toReplace) {
                    board[index1][j] = player;
                    counter ++;
                }
        }
        return counter;
    }
    return 0;
}

int Board::checkRowInRevers(string *board, char player, int index1, int index2) { //
    int tempIndex = -1, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if (index2 - 1 >= 0 && board[index1][index2 - 1] == toReplace) {

        for (int j = index2 - 1; j >= 0; j--) {
            if (board[index1][j] == ' ') return 0;
            if (board[index1][j] == player) {
                tempIndex = j;
                break;
            }
        }
        if (tempIndex == -1) return 0;

        for (int j = index2 - 1; j > tempIndex; j--) {
            if (board[index1][j] == toReplace) {
                board[index1][j] = player;
                counter ++;
            }
        }
        return counter;
    }
    return 0;
}

int Board::checkcol(string *board, char player, int index1, int index2) { //
    int tempIndex = -1, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if (index1 + 1 < size && board[index1 + 1][index2] == toReplace ) {

        for (int i = index1 + 1; i < size; i++) {
            if (board[i][index2] == ' ') return 0;
            if (board[i][index2] == player){
                tempIndex = i;
                break;
            }
        }
        if (tempIndex == -1) return 0;

        for (int i = index1 + 1; i < tempIndex; i++) {
            if (board[i][index2] == toReplace){
                board[i][index2] = player;
                counter++;
            }
        }
        return counter;
    }
    return 0;
}

int Board::checkcolInRevers(string *board, char player, int index1, int index2) { //
    int tempIndex = -1, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if (index1 - 1 >= 0 && board[index1 - 1][index2] == toReplace ){

        for (int i = index1 - 1; i >= 0; i--) {
            if (board[i][index2] == ' ') return 0;
            if (board[i][index2] == player){
                tempIndex = i;
                break;
            }
        }
        if (tempIndex == -1) return 0;

        for (int i = index1 - 1; i > tempIndex; i--) {
            if (board[i][index2] == toReplace){
                board[i][index2] = player;
                counter++;
            }
        }
        return counter;
    }
    return 0;
}

int Board::checkMainSlant(string *board, char player, int index1, int index2) { //
    int flag = 0, tempIndexI = 0, tempIndexJ = 0, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if ((index1 + 1 < size) && (index2 + 1 < size) && (board[index1 + 1][index2 + 1]) == toReplace ){
        int i = index1 + 1 , j = index2 + 1;

        while(i < size && j < size){
            if (board[i][j] == ' ') return 0;
            if (board[i][j] == player){
                tempIndexI = i;
                tempIndexJ = j;
                flag = 1;
                break;
            }
            i++;
            j++;
        }
        if (flag == 0) return 0;

        i = index1 + 1; j = index2 + 1;
        while(i < tempIndexI && j < tempIndexJ){
            if (board[i][j] == toReplace){
                board[i][j] = player;
                counter++;
            }
            i++;
            j++;
        }
        return counter;
    }
    return 0;
}

int Board::checkReversMainSlant(string *board, char player, int index1, int index2) { //
    int flag = 0, tempIndexI = 0, tempIndexJ = 0, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if ((index1 - 1 >= 0) && (index2 - 1 >= 0) && (board[index1 - 1][index2 - 1]) == toReplace ){
        int i = index1 - 1 , j = index2 - 1;

        while(i >= 0 && j >= 0){
            if (board[i][j] == ' ') return 0;
            if (board[i][j] == player){
                tempIndexI = i;
                tempIndexJ = j;
                flag = 1;
                break;
            }
            i--;
            j--;
        }
        if (flag == 0) return 0;

        i = index1 - 1; j = index2 - 1;
        while(i > tempIndexI && j > tempIndexJ){
            if (board[i][j] == toReplace){
               board[i][j] = player;
               counter++;
            }
            i--;
            j--;
        }
        return counter;
    }
    return 0;
}

int Board::checkSecondSlant(string *board, char player, int index1, int index2) {  //
    int flag = 0, tempIndexI = 0, tempIndexJ = 0, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if ((index1 + 1 < size) && (index2 - 1 >= 0) && (board[index1 + 1][index2 - 1]) == toReplace ){
        int i = index1 + 1 , j = index2 - 1;

        while(i < size && j >= 0){
            if (board[i][j] == ' ') return 0;
            if (board[i][j] == player){
                tempIndexI = i;
                tempIndexJ = j;
                flag = 1;
                break;
            }
            i++;
            j--;
        }
        if (flag == 0) return 0;

        i = index1 + 1; j = index2 - 1;
        while(i < tempIndexI && j > tempIndexJ){
            if (board[i][j] == toReplace){
                board[i][j] = player;
                counter++;
            }
            i++;
            j--;
        }
        return counter;
    }
    return 0;
}

int Board::checkReversSecondSlant(string *board, char player, int index1, int index2) { //
    int flag = 0, tempIndexI = 0, tempIndexJ = 0, counter = 0;
    char toReplace = 'x';

    if (player == 'x') toReplace = 'o';

    if ((index1 - 1 >= 0) && (index2 + 1 < size) && (board[index1 - 1][index2 + 1]) == toReplace ) {
        int i = index1 - 1, j = index2 + 1;
        while(j < size && i >= 0){
            if (board[i][j] == ' ') return 0;
            if (board[i][j] == player){
                tempIndexI = i;
                tempIndexJ = j;
                flag = 1;
                break;
            }
            i--;
            j++;
        }
        if (flag == 0) return 0;

        i = index1 - 1; j = index2 + 1;
        while(i > tempIndexI && j < tempIndexJ){
            if (board[i][j] == toReplace){
                board[i][j] = player;
                counter++;
            }
            i--;
            j++;
        }
        return counter;
    }
    return 0;
}

int Board::flip(string *board, char player, int index1, int index2) {
    int sum = 0;
    sum += checkRow(board, player, index1, index2);
    sum += checkRowInRevers(board, player, index1, index2);
    sum += checkcol(board, player, index1, index2);
    sum += checkcolInRevers(board, player, index1, index2);
    sum += checkMainSlant(board, player, index1, index2);
    sum += checkReversMainSlant(board, player, index1, index2);
    sum += checkSecondSlant(board, player, index1, index2);
    sum += checkReversSecondSlant(board, player, index1, index2);
    return sum;
}

int Board::maxFlip(string *board, char player) {
    int maxFlip = 0, Flips= 0;
    string* tempBoard = new string [size];
    tempBoard = newString(tempBoard, board);

    for (int i=0; i<size; i++) {
        for (int j = 0; j < size; j++) {
            newMove(tempBoard, i ,j, player);
            Flips = flip(board, player, i, j);
            if (Flips > maxFlip) maxFlip = Flips;
            newMove(tempBoard, i ,j, ' ');
        }
    }
    return maxFlip;
}

bool Board::correctMove(string* board, int index1, int index2, char player) {
    if (index1 < 0 || index2 < 0 || index1 > size - 1 || index2 > size - 1)
        return false;

    if (board[index1][index2] != ' ') return false;


    newMove(board, index1, index2, player);
    if (flip(board, player, index1, index2) == 0)
        return false;

    else return true;
}

string *Board::getStr() {
    return this->str;
}

bool Board::boardIsEmpty() const {
    Board temp;
    temp.size = this->size;
    temp.resetBoard();
    if (temp.str == this->str) return true;

    return false;
}

bool Board::checkIfPlayerWin(char player) const {
    if (fullBoard()) {
        if (countPlayers() == player)
            return true;
    }
    if (ollSame(player)) return true;
    return false;
}

char Board::countPlayers() const {
    int count1 = 0, count2 = 0; // count 1 for X   count 2 for O

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (str[i][j] == 'x')
                count1++;
            else if (str[i][j] == 'o')
                count2++;
        }
    }

    if (count1 > count2)
        return 'x';
    else if (count1 < count2)
        return 'o';
    else
        return '?';
}

bool Board::ollSame(char player) const {
    char check = 'x';
    if (player == 'x') check ='o';
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (str[i].at(j) == check ) {
                return false;
            }
        }
    }
    return true;
}

bool Board::gameOver(string* board ,char player,Player *Oplayer, Player *Xplayer) {
    char other = 'x';
    if (player == 'x') other = 'o';

    if (checkIfPlayerWin(player)) {
        if (player == 'x') {
            cout << "game over X win !!! " << u8"\U0001F3C6" << "  " << "---> O lose " << "\U0001F622" << endl;
            Xplayer->setPonts(Xplayer->getPonts() + 3);
            Xplayer->setWin(true);
        }
        else {
            cout << "game over O win !!! " << u8"\U0001F3C6" << "  " << "---> O lose " << "\U0001F622" << endl;
            Oplayer->setPonts(Oplayer->getPonts() + 3);
            Oplayer->setWin(true);
        }
        return true;
    }
    if (checkIfPlayerWin(other)) {
        if (player == 'x') {
            cout << "game over O win !!! " << u8"\U0001F3C6" << "  " << "---> X lose " << "\U0001F622" << endl;
            Oplayer->setPonts(Oplayer->getPonts() + 3);
            Oplayer->setWin(true);
        }
        else {
            cout << "game over X win !!! " << u8"\U0001F3C6" << "  " << "---> O lose " << "\U0001F622" << endl;
            Xplayer->setPonts(Xplayer->getPonts() + 3);
            Xplayer->setWin(true);
        }
        return true;
    }
    if (noMoreMoves(board, other)) {
        char ch = countPlayers();
        if (ch == player) {
            if (player == 'x') {
                cout << "game over X win !!! " << u8"\U0001F3C6" << "  " << "---> O lose " << "\U0001F622" << endl;
                Xplayer->setPonts(Xplayer->getPonts() + 3);
                Xplayer->setWin(true);
            }
            else {
                cout << "game over O win !!! " << u8"\U0001F3C6" << "  " << "---> X lose " << "\U0001F622" << endl;
                Oplayer->setPonts(Oplayer->getPonts() + 3);
                Oplayer->setWin(true);
            }
        }
        else if (ch == other) {
            if (player == 'x') {
                cout << "game over X win !!! " << u8"\U0001F3C6" << "  " << "---> O lose " << "\U0001F622" << endl;
                Xplayer->setPonts(Xplayer->getPonts() + 3);
                Xplayer->setWin(true);
            }
            else {
                cout << "game over O win !!! " << u8"\U0001F3C6" << "  " << "---> X lose " << "\U0001F622" << endl;
                Oplayer->setPonts(Oplayer->getPonts() + 3);
                Oplayer->setWin(true);
            }
        } else if (ch == '?') {
            cout << "game over Draw  " << "\U0001F91D" << endl;
            Oplayer->setPonts(Oplayer->getPonts() + 1);
            Xplayer->setPonts(Xplayer->getPonts() + 1);
        }
        return true;
    }
    return false;
}
string *Board::newString(string* toReplace, string* str) {
    for (int i = 0; i < size; i++) {
        toReplace[i] = str[i];
    }
    return toReplace;
}

bool Board::noMoreMoves(string* board ,char player) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != ' ') continue;

            newMove(board, i, j, player);
            if (flip(board, player, i, j) > 0) return false;

            newMove(board, i, j, ' ');
        }
    }
    return true;
}

Board::Board() {
    this->size = 0;
    str = nullptr;
    boardNameFp = "theBestBoards.txt";
}

Board::~Board() {
    delete[] str;
}

bool Board::setSize(int size) {
    if (size < 4 || size % 2 != 0 || size > 8) {
        cout << "try again..." << endl;
        return false;
    } else {
        this->size = size;
        return true;
    }
}

int Board::getSize() const {
    return this->size;
}

void Board::play(Player *Oplaer, Player *Xplayer) {
    bool m;
    int index1, index2;
    string *temp = new string[size];
    Oplaer->symbolPlayer = 'o';
    Xplayer->symbolPlayer = 'x';
    while (true) {
        // x play.
        cout << "X  move (enter  row and column indexes) : ";
        do {
            cin >> index1 >> index2;
            temp = newString(temp, str);
            m = correctMove(temp, index1, index2, 'x');
            if (!m) cout << endl << "invalid move try again : ";
        } while (!m);
        newMove(this->str, index1, index2, 'x');
        flip(this->str, 'x', index1, index2);
        print();
        if (gameOver(temp, 'x', Oplaer, Xplayer)) break;

        //  O play.
        cout << "O  move (enter  row and column indexes) : ";
        do {
            cin >> index1 >> index2;
            temp = newString(temp, str);
            m = correctMove(temp, index1, index2, 'o');
            if (!m) cout << endl << "invalid move try again : ";
        } while (!m);
        newMove(this->str, index1, index2, 'o');
        flip(this->str, 'o', index1, index2);
        print();
        if (gameOver(temp, 'o', Oplaer, Xplayer)) break;
    }
    enterBoardToFp(this->str, this->size);
    delete[] temp;
}

void Board::game1_1(Player *Oplaer, Player *Xplayer) {
    int size;
    cout <<"enter size of board [4 , 6 , 8] : ";
    do {
        cin >>size;
    } while (!setSize(size));
    resetBoard();
    print();
    cout<<endl;
    play(Oplaer, Xplayer);
    if (Oplaer->getWin()){
        cout<<"The winner's name is : "<< Oplaer->getName()<<endl;
    }
    if (Xplayer->getWin()){
        cout<<"The winner's name is :" << Xplayer->getName()<<endl;
    }
}

bool Board::gameOver(string *board, char player) {
    bool m; int index1, index2; string *temp = new string[size];
    while (true) {
        // x play.
        cout << "X  move (enter  row and column indexes) : ";
        do {
            cin >> index1 >> index2;
            temp = newString(temp, str);
            m = correctMove(temp, index1, index2, 'x');
            if (!m) cout << endl << "invalid move try again : ";
        } while (!m);
        newMove(this->str, index1, index2, 'x');
        flip(this->str, 'x', index1, index2);
        print();
        if (gameOver(temp, 'x')) break;

        //  O play.
        cout << "O  move (enter  row and column indexes) : ";
        do {
            cin >> index1 >> index2;
            temp = newString(temp, str);
            m = correctMove(temp, index1, index2, 'o');
            if (!m) cout << endl << "invalid move try again : ";
        } while (!m);
        newMove(this->str, index1, index2, 'o');
        flip(this->str, 'o', index1, index2);
        print();
        if (gameOver(temp, 'o')) break;
    }

    delete[] temp;
}

void Board::enterBoardToFp(string *board, int size) {
    fstream Fp;
    Fp.open("winBoard.txt", ios::out);
    if (Fp.is_open()) {
        for (int i = 0; i < size; i++) {
            Fp<<board[i]<< endl;
        }
        Fp.close();
    }
}

void printMnue(){
    cout << "1. Register a new player" << endl;
    cout << "2. Log in to an existing user" << endl;
    cout << "3. Entry into the league" << endl;
    cout << "4. Print a board of the top players" << endl;
    cout << "5. exit" << endl;
}

void clearScreen() {
    std::system("export TERM=xterm-256color");
    std::system("clear");
}