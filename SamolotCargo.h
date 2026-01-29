#ifndef SAMOLOT_CARGO_H
#define SAMOLOT_CARGO_H

#include "Samolot.h"

class SamolotCargo : public Samolot {
private:
    double ladownosc;
    double aktualny_ladunek;
    
public:
    SamolotCargo(string nr, string mdl, double max_ton);
    void info() override;
    
    bool zaladuj(double ton); //dodaje ładunek
    bool rozladuj(double ton); //zabiera ładunek
    double wolnaLadownosc(); //zwraca ile zostało miejsca naładunekk
};

#endif