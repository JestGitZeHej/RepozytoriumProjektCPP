#include "Lotnisko.h"
#include <iostream>
using namespace std;

void Lotnisko::czyscEkran() {
    system("clear");
}

void Lotnisko::czekajNaEnter() {
    cout << "\nNacisnij Enter, aby kontynuowac...";
    cin.ignore(1000, '\n');
    cin.get();
}

void Lotnisko::pokazMenu() {
    cout << "\n==============================\n";
    cout << "      SYSTEM LOTNISKA\n";
    cout << "==============================\n";
    cout << "1. Dodaj samolot pasazerski\n";
    cout << "2. Dodaj samolot cargo\n";
    cout << "3. Pokaz wszystkie samoloty\n";
    cout << "4. Dodaj pasazera do samolotu\n";
    cout << "5. Zaladuj samolot cargo\n";
    cout << "6. Start samolotu\n";
    cout << "7. Ladowanie samolotu\n";
    cout << "0. Wyjscie\n";
    cout << "==============================\n";
    cout << "Wybierz: ";
}

void Lotnisko::pokazSamoloty() {
    if (samoloty.empty()) {
        cout << "\nBrak samolotow.\n";
        return;
    }
    
    cout << "\n--- LISTA SAMOLOTOW ---\n";
    for (int i = 0; i < samoloty.size(); i++) {
        cout << i + 1 << ". ";
        samoloty[i]->info();
    }
    cout << "-----------------------\n";
}

void Lotnisko::start() {
    int wybor;
    
    do {
        czyscEkran();
        pokazMenu();
        cin >> wybor;
        
        if (wybor == 1) {
            czyscEkran();
            cout << "\n--- DODAWANIE SAMOLOTU PASAZERSKIEGO ---\n";
            
            string nr, model;
            int miejsca;
            
            cout << "Numer: "; 
            cin >> nr;
            
            cout << "Model: "; 
            cin.ignore(1000, '\n');
            getline(cin, model);
            
            cout << "Miejsca: "; 
            cin >> miejsca;
            
            if (miejsca > 0) {
                SamolotPasazerski* nowy = new SamolotPasazerski(nr, model, miejsca);
                samoloty.push_back(nowy);
                cout << "\nDodano samolot pasazerski.\n";
            } else {
                cout << "\nBlad: Liczba miejsc musi byc wieksza od 0!\n";
            }
            
            czekajNaEnter();
        }
        else if (wybor == 2) {
            czyscEkran();
            cout << "\n--- DODAWANIE SAMOLOTU CARGO ---\n";
            
            string nr, model;
            double ladownosc;
            
            cout << "Numer: "; 
            cin >> nr;
            
            cout << "Model: "; 
            cin.ignore(1000, '\n');
            getline(cin, model);
            
            cout << "Ladownosc (t): "; 
            cin >> ladownosc;
            
            if (ladownosc > 0) {
                SamolotCargo* nowy = new SamolotCargo(nr, model, ladownosc);
                samoloty.push_back(nowy);
                cout << "\nDodano samolot cargo.\n";
            } else {
                cout << "\nBlad: Ladownosc musi byc wieksza od 0!\n";
            }
            
            czekajNaEnter();
        }
        else if (wybor == 3) {
            czyscEkran();
            pokazSamoloty();
            czekajNaEnter();
        }
        else if (wybor == 4) {
            czyscEkran();
            pokazSamoloty();
            
            if (!samoloty.empty()) {
                int ktory;
                cout << "\nDo ktorego samolotu? (numer): "; 
                cin >> ktory;
                
                if (ktory >= 1 && ktory <= samoloty.size()) {
                    SamolotPasazerski* pasazerski = dynamic_cast<SamolotPasazerski*>(samoloty[ktory-1]);
                    
                    if (pasazerski != nullptr) {
                        if (pasazerski->czyWLocie()) {
                            cout << "\nSamolot jest w locie - nie mozna dodawac pasazerow!\n";
                        } else if (pasazerski->dodajPasazera()) {
                            cout << "\nDodano pasazera. Wolnych miejsc: " << pasazerski->wolneMiejsca() << endl;
                        } else {
                            cout << "\nBrak miejsc!\n";
                        }
                    } else {
                        cout << "\nTo nie jest samolot pasazerski!\n";
                    }
                } else {
                    cout << "\nNieprawidlowy numer!\n";
                }
            }
            
            czekajNaEnter();
        }
        else if (wybor == 5) {
            czyscEkran();
            pokazSamoloty();
            
            if (!samoloty.empty()) {
                int ktory;
                double ton;
                cout << "\nKtory samolot? (numer): "; 
                cin >> ktory;
                cout << "Ile ton? "; 
                cin >> ton;
                
                if (ktory >= 1 && ktory <= samoloty.size()) {
                    SamolotCargo* cargo = dynamic_cast<SamolotCargo*>(samoloty[ktory-1]);
                    
                    if (cargo != nullptr) {
                        if (cargo->czyWLocie()) {
                            cout << "\nSamolot jest w locie - nie mozna ladowac!\n";
                        } else if (cargo->zaladuj(ton)) {
                            cout << "\nZaladowano. Wolno: " << cargo->wolnaLadownosc() << "t\n";
                        } else {
                            cout << "\nZa duzo! Maksymalnie: " << cargo->wolnaLadownosc() << "t\n";
                        }
                    } else {
                        cout << "\nTo nie jest samolot cargo!\n";
                    }
                } else {
                    cout << "\nNieprawidlowy numer!\n";
                }
            }
            
            czekajNaEnter();
        }
        else if (wybor == 6) {
            czyscEkran();
            pokazSamoloty();
            
            if (!samoloty.empty()) {
                int ktory;
                cout << "\nKtory samolot startuje? (numer): "; 
                cin >> ktory;
                
                if (ktory >= 1 && ktory <= samoloty.size()) {
                    if (samoloty[ktory-1]->czyWLocie()) {
                        cout << "\nTen samolot juz jest w locie!\n";
                    } else {
                        samoloty[ktory-1]->start();
                        cout << "\nSamolot wystartowal!\n";
                    }
                } else {
                    cout << "\nNieprawidlowy numer!\n";
                }
            }
            
            czekajNaEnter();
        }
        else if (wybor == 7) {
            czyscEkran();
            pokazSamoloty();
            
            if (!samoloty.empty()) {
                int ktory;
                cout << "\nKtory samolot laduje? (numer): "; 
                cin >> ktory;
                
                if (ktory >= 1 && ktory <= samoloty.size()) {
                    if (!samoloty[ktory-1]->czyWLocie()) {
                        cout << "\nTen samolot juz jest na ziemi!\n";
                    } else {
                        samoloty[ktory-1]->ladowanie();
                        cout << "\nSamolot wyladowal!\n";
                    }
                } else {
                    cout << "\nNieprawidlowy numer!\n";
                }
            }
            
            czekajNaEnter();
        }
        else if (wybor == 0) {
            czyscEkran();
            cout << "\nDo widzenia!\n\n\n";
        }
        else {
            czyscEkran();
            cout << "\nNieprawidlowy wybor!\n";
            czekajNaEnter();
        }
        
    } while (wybor != 0);
}

Lotnisko::~Lotnisko() {
    for (Samolot* s : samoloty) {
        delete s;
    }
}