#include "SamolotCargo.h"
#include <iostream>
using namespace std;

SamolotCargo::SamolotCargo(string nr, string mdl, double max_ton)
    : Samolot(nr, mdl), ladownosc(max_ton), aktualny_ladunek(0.0) {}

void SamolotCargo::info() {
    cout << "CARGO: " << numer << " (" << model << "), ";
    cout << "Ladunek: " << aktualny_ladunek << "/" << ladownosc << "t, ";
    cout << (czyWLocie() ? "W LOCIE" : "NA ZIEMI") << endl;
}

bool SamolotCargo::zaladuj(double ton) {
    if (aktualny_ladunek + ton <= ladownosc) {
        aktualny_ladunek += ton;
        return true;
    }
    return false;
}

bool SamolotCargo::rozladuj(double ton) {
    if (aktualny_ladunek - ton >= 0) {
        aktualny_ladunek -= ton;
        return true;
    }
    return false;
}

double SamolotCargo::wolnaLadownosc() {
    return ladownosc - aktualny_ladunek;
}