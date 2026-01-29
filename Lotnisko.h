#ifndef LOTNISKO_H
#define LOTNISKO_H

#include "SamolotPasazerski.h"
#include "SamolotCargo.h"
#include <vector>
using namespace std;

class Lotnisko {
private:
    vector<Samolot*> samoloty;
    //poniższe nazwy są intuicyjne
    void pokazMenu(); //pokazuje menu
    void pokazSamoloty(); //pokazuje listę samolotów
    void czyscEkran(); //czyści terminal - dla czytelności i przyjemności użytkowania
    void czekajNaEnter(); //po dokonanej operacji program nie wyświetli menu dopóki nie dostanie "Enter"
    
public:
    void start(); /*tu dzieje się cała magia działania programu, 
    na rozbudowanej instrukcji warunkowej można obsłużyć każdy element z menu programu, 
    a sam program zatrzyma się gdy użytkownik poda coś nie tak, złe wartości itp.*/ 
    ~Lotnisko();
};

#endif