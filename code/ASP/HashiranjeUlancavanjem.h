#pragma once
#include "Hashiranje.h"
#include "ListaPov.h"

template <class Tip>
class HeshiranjeUlancavanjem:public Hashiranje<Tip>
{
	ListaPov<Tip>* Niz;
	int n;
	int IzracunajHash(Tip k)
	{
		return k % n;
	}
public:
	HeshiranjeUlancavanjem(int n=10)
	{
		this->n = n;
		Niz = new ListaPov<Tip>[10];
	}
	void dodaj(Tip k)
	{
		int i = IzracunajHash(k);
		ListaPov<Tip>& lista = Niz[i];
		lista.dodaj(k);
	}
	bool ukloni(Tip k)
	{
		cout << "Uklonjeno: " << k << endl;
		int i = IzracunajHash(k);
		ListaPov<Tip>& lista = Niz[i];
		return lista.ukloni(k);
	}
	void print()
	{
		for (int i=0;i<n;i++)
		{
			cout << "Lista " << i << ": ";
			Niz[i].print();
		}
	}
};
