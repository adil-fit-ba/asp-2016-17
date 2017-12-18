#pragma once
#include "Hashiranje.h"
#include <exception>
#include <iostream>

template <class Tip>
class HeshiranjeOtvorenoAdresiranje :public Hashiranje<Tip>
{
	Tip* Niz;
	int n;
	bool* zauzeto;
	int IzracunajHash(Tip k)
	{
		return k % n;
	}
	int brojac;
public:
	HeshiranjeOtvorenoAdresiranje(int n = 10)
	{
		this->n = n;
		Niz = new Tip[n];
		zauzeto = new bool[n];
		for (int i = 0; i<n; i++)
		{
			zauzeto[i] = false;
		}
		brojac = 0;
	}
	bool jelPun()
	{
		return brojac == n;
	}
	void dodaj(Tip k)
	{
		if (jelPun())
			throw std::exception("greska. Hashset je pun.");
		int i = IzracunajHash(k);

		while (zauzeto[i])
		{
			i++;
			if (i == n)
				i = 0;
		}
		Niz[i] = k;
		zauzeto[i] = true;
	}

	bool jelPrazan()
	{
		return brojac = 0;
	}

	bool ukloni(Tip k)
	{
		if (jelPrazan())
			return false;

		int i = IzracunajHash(k);
		int b = 0;
		while (b != n)
		{
			if (zauzeto[i])
			{
				if (Niz[i] == k)
				{
					zauzeto[i] = false;
					cout << "uklonjeno " << k << endl;
					return true;
				}
			}
			i++;
			b++;
			if (i == n)
				i = 0;
		}
		return false;
	}
	void print()
	{
		for (int i = 0; i<n; i++)
		{
			if (zauzeto[i])
				std::cout << i << ": " << Niz[i] << std::endl;
			else
				std::cout << i << ": (x) " << std::endl;
		}
	}
};
