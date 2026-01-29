#ifndef SAMOLOT_H
#define SAMOLOT_H

#include <string>
using namespace std;

class Samolot {
protected:
    string numer;
    string model;
    bool w_air;
    
public:
    Samolot(string nr, string mdl);
    virtual ~Samolot() = default;
    
    virtual void info() = 0;
    
    bool czyWLocie(); //odpowiada na pytanie czy samolot jest na ziemi czy w powietrzu
    void start(); //startuje samolot
    void ladowanie(); //ląduje samolot
    string getNumer(); //zwraca numer samolotu
};

#endif