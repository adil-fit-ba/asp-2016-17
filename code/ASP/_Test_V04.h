#pragma once

#include <iostream>
#include "PrioritetniRedPov.h"
#include "PrioritetniRedSekv.h"
#include "PrioritetniRedHeap.h"
#include "Osoba.h"
using namespace std;



void napuniPodatke(PrioritetniRed<Osoba>* pRed)
{
	cout << "\n=====TESTIRANJE PRIORITETNOG REDA ====" << endl;

	for (int i = 0; i < 10; i++)
	{
		int random_variable = std::rand() % 100;
		Osoba o (random_variable, "neko ime");
		pRed->add(o);
		//pRed->print("","\n");
	}

	cout << endl;
	while (!pRed->isPrazan())
	{
		Osoba& fW = pRed->ukloni();
		cout << " uklonjeno {" << fW << "} " << endl;
	}
}


void napuniPodatke(PrioritetniRed<Osoba*>* pRed)
{
	cout << "\n=====TESTIRANJE PRIORITETNOG REDA ====" << endl;

	for (int i = 0; i < 10; i++)
	{
		int random_variable = std::rand() % 100;
		Osoba* o = new Osoba(random_variable, "neko ime");
		pRed->add(o);
		//pRed->print("","\n");
	}

	cout << endl;
	while (!pRed->isPrazan())
	{
		Osoba* fW = pRed->ukloni();
		cout << " uklonjeno {" << fW << "} " << endl;
	}
}

void _test_V04()
{
	napuniPodatke(new PrioritetniPov<Osoba>);
	napuniPodatke(new PrioritetniSekv<Osoba>);
	napuniPodatke(new PrioritetniRedHeap<Osoba>);

	napuniPodatke(new PrioritetniPov<Osoba*>);
	napuniPodatke(new PrioritetniSekv<Osoba*>);
	napuniPodatke(new PrioritetniRedHeap<Osoba*>);
}