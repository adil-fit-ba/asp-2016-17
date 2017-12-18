#pragma once

#include "Red.h"

template <class Tip>
class RedSekv : public Red<Tip>
{
private:
	int max;
	int brojac;
	int kraj;
	int pocetak;
	Tip* N;
	void prosiriRed()
	{
		int newMax = max * 2;
		Tip* newN = new Tip[newMax];
		int newI = 0;
		int oldI = pocetak;
		while (newI < brojac)
		{
			newN[newI++] = N[oldI++];
			if (oldI == max)
				oldI = 0;
		}
		max = newMax;
		delete[] N;
		N = newN;
		pocetak = 0;
		kraj = brojac;
		cout << "\nRED: rekonstrukcija - nova velicina je " << newMax << endl;
	}
public:
	RedSekv(int max=10)
	{
		this->max = max;
		brojac = 0;
		kraj = 0;
		pocetak = 0;
		N = new Tip[max];
	}
	void dodaj(Tip v)
	{
		if (brojac == max)
			prosiriRed();
		
		N[kraj] = v;
		kraj++;
		if (kraj == max)
			kraj = 0;

		brojac++;
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog reda.");

		Tip x = N[pocetak];
		pocetak++;
		if (pocetak == max) 
			pocetak = 0;

		brojac--;
		return x;
	}

	bool isPrazan()
	{
		return brojac == 0;
	}

	void print(string pre = "", string post = ", ")
	{	
		int i = pocetak;
		int b = 0;
		while (b++ < brojac)
		{
			cout << pre << N[i++] << post;
			if (i == max)
				i = 0;
		}
	}

	bool sadrzi(Tip value)
	{
		for (int i = 0; i < brojac; i++)
		{
			if (IsJednako(N[i],value))
				return true;
		}
		return false;
	}
};


