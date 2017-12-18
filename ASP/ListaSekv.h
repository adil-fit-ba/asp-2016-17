#pragma once

#include "Lista.h"

template <class Tip>
class ListaSekv : public Lista<Tip>
{
private:
	Tip* N;
	int brojac;
	int max;
	void prosiriListu()
	{
		int newMax = max * 2;
		Tip* novi = new Tip[newMax];
		for (int i = 0; i < max; i++)
		{
			novi[i] = N[i];
		}
		delete[] N;
		N = novi;
		max = newMax;
		cout << " LISTA: rekonstrukcija - nova velicina je " << newMax << endl;
	}
public:
	ListaSekv(int max = 10)
	{
		this->max = max;
		N = new Tip[max];
		brojac = 0;
	}

	ListaSekv(Tip* niz, int velicina, int max = 10) : ListaSekv(max)
	{
		for (int i = 0; i < velicina; i++)
		{
			dodaj(niz[i]);
		}
	}

	ListaSekv(Lista<Tip>* lista, int max = 10) :ListaSekv(max)
	{
		for (int i = 0; i < lista->count(); i++)
		{
			dodaj(lista->get(i));
		}
	}

	ListaSekv(Lista<Tip>& lista, int max = 10) :ListaSekv(&lista, max)
	{
	}

	void dodaj(Tip v)
	{
		if (max == brojac)
		{
			prosiriListu();
		}

		N[brojac] = v;
		brojac++;
	}

	Tip ukloni()
	{
		if (isPrazan())
		{
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog steka.");
		}

		brojac--;
		Tip t = N[brojac];
		return t;
	}

	bool isPrazan()
	{
		return (brojac == 0);
	}

	int count()
	{
		return brojac;
	}

	void print(string pre = "", string post = ", ")
	{
		int i = 0;
		while (i < brojac)
		{
			cout << pre << N[i++] << post;
		}
		cout << endl;
	}

	Tip& get(int i)
	{
		if (i  > brojac)
			throw exception("indeks je veći od brojaca");

		return N[i];
	}

	Tip& operator[](int i)
	{
		return get(i);
	}

	void set(int i, Tip v)
	{
		get(i) = v;
	}

	bool sadrzi(Tip v) 
	{
		for (int i = 0; i < brojac; i++)
		{
			if (N[i] == v)
				return true;
		}
		return false;
	}

	Tip* getNiz()
	{
		return niz;
	}

	Tip* formirajNiz()
	{
		Tip* niz = new Tip[this->brojac];

		for (int i = 0; i < this->brojac; i++)
		{
			niz[i] = this->N[i];
		}
		return niz;
	}
};


