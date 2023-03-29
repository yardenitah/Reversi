#include "Dolphin.h"

void Dolphin::kindFp() {
    fstream Fp;
    Fp.open(Mammal::nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Dolphin : ";
        Mammal::inToFp();
        Fp.close();
    }
}

void Dolphin::printData() {
    cout << "IM a Dolphin  : " << endl;
    cout << "the name is: " << name << endl;
    cout << "the user name if: " << userName << endl;
}
