#include "Dog.h"

void Dog::kindFp() {
    fstream Fp;
    Fp.open(nameFP, ios::app);
    if (Fp.is_open()) {
        Fp << " Dog : ";
        Mammal::inToFp();
        Fp.close();
    }
}

void Dog::printData() {
    cout << "IM a dog : " << endl;
    cout << "my name is: " << name << endl;
    cout << "my user name if: " << userName << endl;
    printDog();
}

void Dog::printDog() {
    std::cout << "   / \\__" << std::endl;
    std::cout << "  (    @\\___" << std::endl;
    std::cout << "   /         O" << std::endl;
    std::cout << "  /   (_____/ " << std::endl;
    std::cout << " /_____/   U " << std::endl;
}
