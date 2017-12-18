#pragma once

#include "PrioritetniRed.h"


template <class Tip>
class PrioritetniSekv : public PrioritetniRed<Tip>
{
	int brojac;
	Tip* N;
	int max;
	void prosiriPR()
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
		cout << "\nPR: rekonstrukcija - nova velicina je " << newMax << endl;
	}
public:
	PrioritetniSekv(int max = 10)
	{
		this->max = max;
		this->brojac = 0;
		this->N = new Tip[max];
	}

	bool sadrzi(Tip v)
	{
		for (int i = 0; i < brojac; i++)
		{
			if (N[i] == v)
			{
				return true;
			}
		}
		return false;
	}

	void add(Tip v)
	{
		if (brojac == max)
		{
			prosiriPR();
		}
		N[brojac] = v;
		brojac++;
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog pr. reda.");

		int maxI = 0;
		Tip maxV = N[0];

		for (int i = 1; i < brojac; i++)
		{
			if (IsVece(N[i], maxV))
			{
				maxV = N[i];
				maxI = i;
			}
		}

		brojac--;
		
		Tip info = N[maxI];
		N[maxI] = N[brojac];
		

		return info;
	}

	bool isPrazan()
	{
		return brojac == 0;
	}

	void print(string pre = "", string post = ", ")
	{
		int i = 0;
		while (i < brojac)
		{
			cout << pre << N[i++] << post;
		}
	}
};


