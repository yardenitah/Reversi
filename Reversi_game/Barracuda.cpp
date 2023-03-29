#include "Barracuda.h"

void Barracuda::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Barracuda : ";
        Barracuda::inToFp();
        Fp.close();
    }
}

void Barracuda::printData() {
    cout << "IM a barracuda : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
}
