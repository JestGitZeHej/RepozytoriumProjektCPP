#include "Samolot.h"
#include <iostream>
using namespace std;

Samolot::Samolot(string nr, string mdl) 
    : numer(nr), model(mdl), w_air(false) {}

bool Samolot::czyWLocie() {
    return w_air;
}

void Samolot::start() {
    w_air = true;
    cout << numer << " wystartowal.\n";
}

void Samolot::ladowanie() {
    w_air = false;
    cout << numer << " wyladowal.\n";
}

string Samolot::getNumer() {
    return numer;
}