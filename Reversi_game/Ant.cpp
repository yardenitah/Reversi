#include "Ant.h"

void Ant::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Ant : ";
        Ant::inToFp();
        Fp.close();
    }
}

void Ant::printData() {
    cout << "IM a ant : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
}
