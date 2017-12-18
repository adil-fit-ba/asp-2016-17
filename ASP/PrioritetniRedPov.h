#pragma once

#include "PrioritetniRed.h"
#include "UsporedbaGeneric.h"

template <class Tip>
class PrioritetniPov : public PrioritetniRed<Tip>
{
	Cvor<Tip>* prvi;
public:
	PrioritetniPov()
	{
		prvi = nullptr;
	}

	void add(Tip v)
	{
		Cvor<Tip>* n = new Cvor<Tip>(v, nullptr);

		Cvor<Tip>* t = prvi;
		Cvor<Tip>* pt = nullptr;

		while (t != nullptr)
		{
			if (IsVece(n->info, t->info))
				break;
			
			pt = t;
			t = t->next;
		}

		if (pt == nullptr)
		{
			prvi = n;
		}
		else
		{
			pt->next = n;
		}

		n->next = t;
	}

	Tip ukloni()
	{
		if (isPrazan())
			throw exception("Greska. Nije moguce ukloniti elemenat iz praznog pr. reda.");

		Cvor<Tip>* t = prvi;

		prvi = prvi->next;
		Tip x = t->info;
		delete t;
		return x;
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
};


