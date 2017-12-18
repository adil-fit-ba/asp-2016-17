#pragma once

#include "PrioritetniRed.h"
#include "UsporedbaGeneric.h"

template <class Tip>
class PrioritetniRedHeap : public PrioritetniRed<Tip>
{
	int max;
	int brojac;
	Tip* N;
	void rotacija(Tip& x1, Tip& x2)
	{
		Tip temp = x1;
		x1 = x2;
		x2 = temp;
	}
	void BubbleDown(int index)
	{
		int lijevoDijete = 2 * index;
		int desnoDijete = 2 * index + 1;

		if (2 * index > brojac)
			return;

		int maxI = index;

		if (IsVece(N[lijevoDijete], N[index]))
			maxI = lijevoDijete;

		if (2 * index + 1 <= brojac)
		{
			if (IsVece(N[desnoDijete], N[maxI]))
				maxI = desnoDijete;
		}

		if (maxI != index)
		{
			rotacija(N[maxI], N[index]);
			BubbleDown(maxI);
		}
	}

	void BubbleUp(int index)
	{
		if (index == 1)
			return;

		int roditelj = index / 2;

		if (IsVece(N[index], N[roditelj]))
		{
			rotacija(N[roditelj], N[index]);
			BubbleUp(roditelj);
		}
	}
	
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
	PrioritetniRedHeap(int max=3)
	{
		this->max = max;
		N = new Tip[max];
		brojac = 0;
	}
	void add(Tip v)
	{
		if (brojac == max-1)
			prosiriPR();

		brojac++;
		N[brojac] = v;

		BubbleUp(brojac);
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog pr. reda.");
		
		Tip x = N[1];
		N[1] = N[brojac];
		brojac--;

		BubbleDown(1);
		return x;
	}

	bool isPrazan()
	{
		return (brojac == 0);
	}

	void print(string pre = "", string post = ", ")
	{
		for (int i = 1; i <= brojac; i++)
		{
			cout << N[i] << endl;
		}
	}
};

