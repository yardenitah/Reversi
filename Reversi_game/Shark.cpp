#include "Shark.h"

void Shark::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Shark : ";
        Shark::inToFp();
        Fp.close();
    }
}

void Shark::printData() {
    cout << "IM a shark : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
}
