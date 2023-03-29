#include "Wasp.h"

void Wasp::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Wasp : ";
        Wasp::inToFp();
        Fp.close();
    }
}

void Wasp::printData() {
    cout << "IM a wasp : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
}

