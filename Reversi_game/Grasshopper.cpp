#include "Grasshopper.h"

void Grasshopper::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Grasshopper : ";
        Grasshopper::inToFp();
        Fp.close();
    }
}

void Grasshopper::printData() {
    cout << "IM a grasshopper : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
}

