#include "Bug.h"

void Bug::kindToFp() {
    fstream FP;
    FP.open(nameFP, ios::app);
    if (FP.is_open()) {
        FP << " Bug : " << endl;
        Bug::inToFp();
        FP.close();
    }
}
