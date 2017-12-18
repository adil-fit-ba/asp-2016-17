#pragma once

#include <iostream>
#include <string>

using namespace std;


class Osoba
{
public:
	int Id;
	string ime;
	Osoba()
	{

	}
	Osoba(int id, string ime)
	{
		this->ime = ime;
		this->Id = id;
	}
	friend ostream& operator<< (ostream& out, const Osoba& osoba) {
		//Ova funkcija omogucava ispis objekta osoba pomocu operatora "<<", npr. "Osoba a; cout << a;"
		//Studenti ne moraju poznavati implementaciju ove funkcije za ispit.
		out << osoba.Id << "-" << osoba.ime;
		return out;
	}
	friend ostream& operator<< (ostream& out, const Osoba* osoba) {
		//Ova funkcija omogucava ispis objekta osoba* pomocu operatora "<<", npr. "Osoba* a=new Osoba; cout << a;"
		//Studenti ne moraju poznavati implementaciju ove funkcije za ispit.
		out << osoba->Id << "-" << osoba->ime;
		return out;
	}

	friend bool operator>(Osoba& left, Osoba& right)
	{
		return left.Id < right.Id;
	}
};

