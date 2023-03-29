#include "Mammal.h"

void Mammal::kindToFp() {
    fstream FP;
    FP.open(nameFP, ios::app);
    if (FP.is_open()) {
        FP << " Mammals : " << endl;
        Mammal::inToFp();
        FP.close();
    }
}
