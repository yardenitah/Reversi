#include "Fish.h"

void Fish::kindToFp() {
    fstream FP;
    FP.open(nameFP, ios::app);
    if (FP.is_open()) {
        FP << " Fish : " << endl;
        Fish::inToFp();
        FP.close();
    }
}
