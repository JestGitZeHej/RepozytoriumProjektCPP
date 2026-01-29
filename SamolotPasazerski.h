#ifndef SAMOLOT_PASAZERSKI_H
#define SAMOLOT_PASAZERSKI_H

#include "Samolot.h"

class SamolotPasazerski : public Samolot {
private:
    int max_pasazerow;
    int akt_pasazerow;
    
public:
    SamolotPasazerski(string nr, string mdl, int max_pas);
    void info() override;
    
    bool dodajPasazera(); //umożliwia przypisanie pasażera do samolotu pasazerskiego
    bool usunPasazera(); //usuwa pasazera
    int wolneMiejsca(); //zwraca ile zostało wolnych miejsc
};

#endif