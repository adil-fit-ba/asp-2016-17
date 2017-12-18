#pragma once

#include "Stek.h"

template <class Tip>
class StekSekv : public Stek<Tip>
{
	int brojac;
	Tip* N;
	int max;
private:
	void prosiriStek()
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
		cout << "\nSTEK: rekonstrukcija - nova velicina je " << newMax << endl;
	}
public:
	StekSekv(int max = 10)
	{
		this->max = max;
		this->brojac = 0;
		this->N = new Tip[max];

	}
	void dodaj(Tip v)
	{
		if (brojac == max)
		{
			prosiriStek();
		}
		N[brojac] = v;
		brojac++;
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog steka.");
		brojac--;
		Tip x = N[brojac];

		return x;
	}

	Tip vrh()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce uzeti elemenat iz praznog steka.");

		return N[brojac-1];
	}

	bool isPrazan()
	{
		return brojac == 0;
	}

	void print(string pre = "", string post = ", ")
	{
		for (int i = 0; i < brojac; i++)
		{
			cout << pre << N[i] << post;
		}
	}

	bool sadrzi(Tip value)
	{
		for (int i = 0; i < brojac; i++)
		{
			if (IsJednako(N[i], value))
				return true;
		}
		return false;
	}
};


