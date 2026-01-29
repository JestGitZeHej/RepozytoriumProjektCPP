# System Zarządzania Lotniskiem

Prosty system symulujący zarządzanie lotniskiem napisany w C++. Program demonstruje dziedziczenie i polimorfizm w programowaniu obiektowym.

# Obsługa

Uruchom program, pojawi się ekran powitalny.
Naciśnij Enter, aby przejść do menu głównego.

Wybierz 1 -> "Dodaj samolot pasażerski"
   - Wpisz numer: SP-001
   - Wpisz model: Boeing 737 (może zawierać spacje)
   - Wpisz miejsca: 180

Wybierz 2 -> "Dodaj samolot cargo"
   - Wpisz numer: CARGO-01
   - Wpisz model: Boeing 747F
   - Wpisz ładowność: 100 (domyślna jednostka to tony)

Wybierz 3 -> "Pokaż wszystkie samoloty"
Zobaczysz:
  1. PASAZERSKI: SP-001 (Boeing 737), Pasazerow: 0/180, NA ZIEMI
  2. CARGO: CARGO-01 (Boeing 747F), Ladunek: 0/100t, NA ZIEMI

Wybierz 4 -> "Dodaj pasażera do samolotu"
- Wybierz numer samolotu z listy (np. 1)
- System automatycznie doda pasażera
- Jeśli brak miejsc: "Brak miejsc!"
- Jeśli to nie pasażerski: "To nie jest samolot pasażerski!"

Wybierz 5 -> "Załaduj samolot cargo"
- Wybierz numer samolotu cargo (np. 2)
- Podaj ilość ton (np. 50)
- System sprawdzi czy się zmieści
- Jeśli za dużo: "Za duzo! Maksymalnie: Xt"

Wybierz 6 -> "Start samolotu"
- Wybierz numer samolotu
- Samolot zmieni status na "W LOCIE"
- Nie można dodawać pasażerów/ładunku w locie

Wybierz 7 -> "Lądowanie samolotu"
- Wybierz numer samolotu w locie
- Samolot wróci na ziemię


    Po każdej operacji możesz wybrać 3, aby zobaczyć:
    - Zmianę liczby pasażerów/ładunku
    - Zmianę statusu (NA ZIEMI/W LOCIE)
    - Aktualne zapełnienie

Wybierz 0 -> "Wyjście"
Program zakończy działanie po wyczyszczeniu pamięci.


Miłej zabawy!
