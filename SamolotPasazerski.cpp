#include "SamolotPasazerski.h"
#include <iostream>
using namespace std;

SamolotPasazerski::SamolotPasazerski(string nr, string mdl, int max_pas)
    : Samolot(nr, mdl), max_pasazerow(max_pas), akt_pasazerow(0) {}

void SamolotPasazerski::info() {
    cout << "PASAZERSKI: " << numer << " (" << model << "), ";
    cout << "Pasazerow: " << akt_pasazerow << "/" << max_pasazerow << ", ";
    cout << (czyWLocie() ? "W LOCIE" : "NA ZIEMI") << endl;
}

bool SamolotPasazerski::dodajPasazera() {
    if (akt_pasazerow < max_pasazerow) {
        akt_pasazerow++;
        return true;
    }
    return false;
}

bool SamolotPasazerski::usunPasazera() {
    if (akt_pasazerow > 0) {
        akt_pasazerow--;
        return true;
    }
    return false;
}

int SamolotPasazerski::wolneMiejsca() {
    return max_pasazerow - akt_pasazerow;
}