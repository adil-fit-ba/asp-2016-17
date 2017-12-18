#pragma once

#include "Cvor.h"
#include "Stek.h"

template <class Tip>
class StekPov:public Stek<Tip>
{
private:
	Cvor<Tip>* prvi;
public:
	StekPov()
	{
		prvi = nullptr;
	}
	void dodaj(Tip v)
	{
		Cvor<Tip>* n = new Cvor<Tip>(v, prvi);
		prvi = n;
	}

	Tip ukloni()
	{
		if (isPrazan())		
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog steka.");
		
		Cvor<Tip>* t = prvi;

		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
	}

	Tip vrh()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce uzeti elemenat iz praznog steka.");

		return prvi->info;
	}

	bool isPrazan()
	{
		return prvi == nullptr;
	}

	void print(string pre = "", string post = ", ")
	{
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			cout << pre << t->info << post;
			t = t->next;
		}
	}

	virtual bool sadrzi(Tip value)
	{
		Cvor<Tip>* t = prvi;
		while (t != nullptr)
		{
			if (IsJednako(t->info, value))
				return true;
		}
		return false;
	}
};

