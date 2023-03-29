#include "Board.h"
#include "Test.h"
#include "League.h"


int main() {
    int size, i=0;
    string name, username, password;
    Board board;
    PlayerList list;
    League league;



    char option;
    int flag = 0;
    int flag2 = 0;
    while (flag != 1) {
        if (flag2 == 0) {
            cout << endl;
            printMnue();
        }
        flag2 = 0;
        cin >> option;
        cout << endl;
        switch (option) {
            case '1':
                cout << " ente name and password and username" << endl;
                cin >> name>> password >>username;
                if (list.insertPlayer(name, password, username, list)) {
                    cout << "The user successfully joined" <<endl;
                }
                else cout <<"Problem with the registration process (the username you chose may already exist).." <<endl;

                break;

            case '2':
//                cout << " ente name and password and username" << endl;
//                cin >> name>> password >>username;
//                if (list.insertPlayer(name, password, username, list)) {
//                    cout << "The user successfully joined" <<endl;
//                }
//                else cout <<"Problem with the registration process (the username you chose may Not exist).." <<endl;
                break;

            case '3':
                if (!list.iFleaguePossible()) continue;
                int index1, index2;
                league.randTwoIndexses(list.getsize(),&index1, &index2);
                board.game1_1(list.list[index1], list.list[index2]);
                break;

            case '4':

                break;

            case '5':
                flag = 1;
                break;

            default:
                cout << "invalid input try again:";
                flag2 = 1;
                break;
        }
    }

    cout<<endl<<"Bye Bye"<<endl;
    return 0;
}

