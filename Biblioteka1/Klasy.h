﻿#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Ksiazka {
	friend class BazaKsiazek;
	friend ostream& operator<<(ostream& os, const Ksiazka& ksiazka);

	int id;

public:
	string tytul;
	string autor;
	int ISBN;
	Ksiazka();
	Ksiazka(string t, string au, int isbn);
};

class BazaKsiazek {
	vector<Ksiazka> lista_ksiazek;
	string nazwa_pliku = "baza_ksiazek.txt";

	void loadFromFile();
	void saveToFile();
public:
	BazaKsiazek();
	void add(string t, string au, int isbn);
	bool wyszukaj_czy_jest(int isbn) const;
	bool wyszukaj_czy_jest(string tyt) const;
	Ksiazka wyszukaj(int isbn) const;
};

class Czytelnik {
	friend class BazaUzytkownikow;
	friend ostream& operator<<(ostream& os, const Czytelnik& czytelnik);

	int id;
	string imie;
	string nazwisko;
	string email;
	string adres;
	int numer_tel;
	string login;
	string haslo;

public:
	Czytelnik(string i, string n, string e, string a, int tel, string l, string h);
	Czytelnik();
	bool checkPass(const string& pass) const; //sprawdzamy has�o
};

class BazaUzytkownikow {
	vector<Czytelnik> lista_czytelnikow;
	string nazwa_pliku = "baza_czytelnikow.txt";

	void loadFromFile();
	void saveToFile();

public:
	BazaUzytkownikow();
	void add(string i, string n, string e, string a, int tel, string l, string h);
	bool wyszukaj_czy_jest(const string& login) const;
	Czytelnik wyszukaj(const string& login) const;
};



class Wypozyczenie {
	string data_wypozyczenia;
	string data_oddania;
	bool zakonczone;
	int numer_skrytki;
	Ksiazka  wyp_ksiazka;
	Czytelnik wyp_czyt;
public:
	Wypozyczenie(string data_wyp, string data_odd, bool zak, int numer_skr, Ksiazka  wyp_k, Czytelnik wyp_czyt);
	Wypozyczenie();

	void end_wyp();
};

class OsobaBezKonta {

public:
	Czytelnik zaloz_konto(string i, string n, string e, string a, int tel);
};

class Bibliotekarz {
	string login;
	string haslo;
	void dodanie_ksiazki(string t, string au, int isbn, BazaKsiazek baza);
	//void usuniecie_ksiazki(Ksiazka k, BazaKsiazek baza);
};

class Skrytka {
	friend class BazaSkrytek;
	friend ostream& operator<<(ostream& os, const Skrytka& skrytka);

	int id;
	bool wolna;
	int numer_wypozyczenia;

public:
	Skrytka();
	Skrytka(int id, bool wolna, int numer_wypozyczenia);
};

class BazaSkrytek {
	vector<Skrytka> lista_skrytek;
	string nazwa_pliku = "baza_skrytek.txt";

	void loadFromFile(); // Wczytanie bazy z pliku
	void saveToFile();   // Zapis ca�ej bazy do pliku

public:
	BazaSkrytek();
	void add(int id, bool wolna, int numer_wypozyczenia);
	void zajmij(int id, int id_wyp);
	void zwolnij(int id);
	void usun_skrytke(int id);
	bool wyszukaj_czy_jest(int id) const;
	Skrytka wyszukaj(int id) const;
};
