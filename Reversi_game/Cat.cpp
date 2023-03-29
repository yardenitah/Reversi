#include "Cat.h"

void Cat::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Cat : ";
        Mammal::inToFp();
        Fp.close();
    }
}

void Cat::printData() {
    cout << "IM a cat : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
    printCat();
}

void Cat::printCat() {
    cout << "  /\\_/\\  \n";
    cout << "( o   o )\n";
    cout << "=(  =  )=\n";
    cout << " (\\\"_\\\")\n";
}

