#include <iostream>
#include <string>
#include <vector>
#include "Klasy.h"

using namespace std;

int wyszukaj(BazaKsiazek& b);

int main() {
    BazaKsiazek Baza_Ksiazek;
    BazaSkrytek Baza_Skrytek;
    BazaUzytkownikow Baza_Uzytkownikow;
    Bibliotekarz bibliotekarz;

    int op = 0;
    string imie, nazwisko, email, adres, login, haslo;
    int numer_tel;
    bool ster = true;

    Baza_Ksiazek.add("Biblia", "Nieznany", 1);
    Baza_Ksiazek.add("Obcy", "Alber Camus", 2);
    Baza_Ksiazek.add("Analiza Matematyczna 2", "Niedoba", 3);

    while (ster) {
        switch (op) {
        default:
            cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
            op = 0; // Powr�t do menu g��wnego
            break;
        case -1:
            ster = false;
            break;

        case 0:
            cout << "\n---------------------------------------\n";
            cout << "-1 - Wyjdz\n";
            cout << "1 - Zaloguj sie\n";
            cout << "2 - Stworz konto\n";
            cout << "3 - Wyszukaj ksiazke\n";
            cout << "Wybierz opcje: ";
            cin >> op;
            cout << "\n---------------------------------------\n";
            break;

        case 1:
            cout << "\n---------------------------------------\n";
            cout << "Podaj login (lub napisz 'menu', aby wrocic): ";
            cin >> login;

            if (login == "menu") {
                op = 0;
                break;
            }

            cout << "Podaj has�o: ";
            cin >> haslo;

            if (Baza_Uzytkownikow.wyszukaj_czy_jest(login)) {
                auto user = Baza_Uzytkownikow.wyszukaj(login);
                if (user.checkPass(haslo)) {
                    cout << "Udalo sie zalogowac.\n";
                    op = 0;
                }
                else {
                    cout << "Zle haslo.\n";
                    op = 1;
                }
            }
            else {
                cout << "Nie ma takiego konta.\n";
                op = 0;
            }
            break;

        case 2:
            cout << "\n---------------------------------------\n";
            cout << "Podaj swoje dane:\n";

            cout << "Imie: ";
            cin >> imie;

            cout << "Nazwisko: ";
            cin >> nazwisko;

            cout << "Email: ";
            cin >> email;

            cout << "Adres zamieszkania: ";
            cin >> adres;

            cout << "Numer telefonu: ";
            cin >> numer_tel;

            cout << "Podaj login: ";
            cin >> login;

            cout << "Podaj haslo: ";
            cin >> haslo;

            if (!Baza_Uzytkownikow.wyszukaj_czy_jest(login)) {
                Baza_Uzytkownikow.add(imie, nazwisko, email, adres, numer_tel, login, haslo);
                cout << "Dodano konto.\n";
            }
            else {
                cout << "Konto o takim loginie juz istnieje.\n";
                op = 2;
            }
            cout << "\n---------------------------------------\n";
            op = 0;
            break;

        case 3:
            cout << "\n---------------------------------------\n";
            wyszukaj(Baza_Ksiazek);
            cout << "\n---------------------------------------\n";
            op = 0;
            break;

        }

    }

    return 0;
}

int wyszukaj(BazaKsiazek& b) {
    int wyb;
    cout << "Wyszukaj po:\n1) - Tytule\n2) - Numerze ISBN\n";
    cin >> wyb;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Nieprawidlowe dane.\n";
        return 0; // Powr�t do menu
    }

    string tytul;
    int num;

    if (wyb == 1) {
        cout << "Podaj tytul: ";
        cin >> tytul;
        if (b.wyszukaj_czy_jest(tytul)) {
            cout << "Znaleziono " << tytul << ".\n";
        }
        else {
            cout << "Nie znaleziono " << tytul << ".\n";
        }
    }
    else if (wyb == 2) {
        cout << "Podaj numer ISBN: ";
        cin >> num;
        if (b.wyszukaj_czy_jest(num)) {
            cout << "Znaleziono ksiazke o numerze ISBN: " << num << ".\n" << "O tytule: " << b.wyszukaj(num).tytul << "\n";
        }
        else {
            cout << "Nie znaleziono ksiazki o numerze ISBN: " << num << ".\n";
        }
    }
    else {
        cout << "Nieprawidlowy wybor.\n";
    }
    return 0; // Powr�t do menu g��wnego
}