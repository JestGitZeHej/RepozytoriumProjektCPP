#include "Lotnisko.h"
#include <iostream>
using namespace std;

int main() {
    system("clear"); //Poniżej ekran powitalny na start
    cout << "===========================================\n";
    cout << "       SYSTEM ZARZADZANIA LOTNISKIEM\n";
    cout << "              Wersja 2.1\n";
    cout << "===========================================\n\n";
    
    cout << "Program demonstruje programowanie obiektowe\n";
    cout << "z dziedziczeniem zrealizowane w C++\n\n";
    cout << "Franciszek Dylewski\n";
    cout << "III semestr, Fizyka Techniczna\n";
    cout << "Politechnika Warszawska\n\n";
    
    cout << "Nacisnij Enter, aby rozpoczac...";
    cin.get();
    
    Lotnisko system;
    system.start();
    
    return 0;
}