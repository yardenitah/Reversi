#ifndef REVERSI_GAME_BOARD_H
#define REVERSI_GAME_BOARD_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "PlayerList.h"
using namespace std;

class Board {
public:
    Board();
    ~Board();
    void resetBoard();
    bool setSize(int size);
    int getSize() const;
    string* getStr();
    void print() const;
    void game1_1(Player *Oplaer, Player *Xplayer);
    void play(Player *Oplaer, Player *Xplayer);
    void play_computer();
    bool win;



private:
    int size;
    string* str; // board
    struct Move{
        int indexI, indexJ;
        int evaluation;
    };
    string boardNameFp;

    Move miniMax(string* board, char player, int steps) ;
    int boardEvaluatino(string* board);
    bool  gameOver(string* board ,char player, Player *Oplayer, Player *Xplayer);
    bool  gameOver(string* board ,char player);
    bool checkIfPlayerWin(char player) const;
    bool ollSame(char player) const;
    bool fullBoard() const;
    bool boardIsEmpty() const;
    void computerMove(int *index1 , int* index2);
    char countPlayers() const;
    // private:
    void newMove(string* board, int index1, int index2, char player);
    int checkRow(string *board, char player, int index1, int index2); //
    int checkRowInRevers(string *board, char player, int index1, int index2); //
    int checkcol(string *board, char player, int index1, int index2); //
    int checkcolInRevers(string *board, char player, int index1, int index2); //
    int checkMainSlant(string *board, char player, int index1, int index2); //
    int checkReversMainSlant(string *board, char player, int index1, int index2); //
    int checkSecondSlant(string *board, char player, int index1, int index2); //
    int checkReversSecondSlant(string *board, char player, int index1, int index2); //
    int flip(string *board, char player, int index1, int index2);
    bool correctMove(string* board, int index1, int index2, char player);
    bool noMoreMoves(string* board ,char player) ;
    int maxFlip(string* board ,char player) ;
    string* newString(string* toReplace, string* str);
    void enterBoardToFp(string* board, int size);
    void bestMove();
    void setStr(string* str);
};

void printMnue();
#include <iostream>

void clearScreen();

#endif //REVERSI_GAME_BOARD_H