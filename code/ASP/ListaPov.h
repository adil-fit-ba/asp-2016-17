#pragma once

#include "Lista.h"
#include "Cvor.h"

template <class Tip>
class ListaPov: public Lista<Tip>
{
private:
	int brojac;
	Cvor<Tip>* prvi;
public:
	ListaPov()
	{
		brojac = 0;
		prvi = nullptr;
	}

	ListaPov(Tip* niz, int velicina) :ListaPov()
	{ 
		for (int i = 0; i < velicina; i++)
		{
			dodaj(niz[i]);
		}
	}

	ListaPov(Lista<Tip>* lista) :ListaPov()
	{
		for (int i = 0; i < lista->count(); i++)
		{
			dodaj(lista.get(i));
		}
	}

	ListaPov(Lista<Tip>& lista) :ListaPov(&lista)
	{
	
	}

	void dodaj(Tip v)
	{
		Cvor<Tip>* t = new Cvor<Tip>(v, prvi);
		prvi = t;
		brojac++;
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz prazne liste");

		brojac--;
		Cvor<Tip>* t = prvi;
		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}

	bool ukloni(Tip tip)
	{
		//nova funkcija koja se koristi u lekciji Hasiranje
		Cvor<Tip>* t = prvi;
		Cvor<Tip>* pt = nullptr;

		while (t != nullptr)
		{
			if (tip == t->info)
				break;
			pt = t;
			t = t->next;
		}
		if (t == nullptr)
		{
			return false;
		}
		if (pt == nullptr)
		{
			prvi = t->next;
		}
		else
		{
			pt->next = t->next;
		}
		delete t;
		return true;
	}

	
	bool isPrazan()
	{
		return (prvi == nullptr);
	}

	int count()
	{
		return brojac;
	}

	void print(string pre="", string post=", ")
	{
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			cout << pre << t->info << post;
			t = t->next;
		}
		cout << endl;
	}

	Tip& get(int i)
	{
		if (i  > brojac)
			throw exception("indeks je veći od brojaca");

		Cvor<Tip>* t = prvi;
		for (int j = 0; j < (brojac - i - 1); j++)
		{
			t = t->next;
		}
		return t->info;
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
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			if (t->info == v)
				return true;
			t = t->next;
		}
		return false;
	}

	Tip* formirajNiz()
	{
		Tip* niz = new Tip[this->brojac];

		int b = 0;
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			niz[b++] = t->info;
			t = t->next;
		}
		return niz;
	}
};


