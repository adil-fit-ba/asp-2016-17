#pragma once

#include <iostream>
#include "StekPov.h"
#include "StekSekv.h"
#include "Osoba.h"
using namespace std;



void napuniPodatke(Stek<Osoba*>* stek)
{
	cout << "\n=====TESTIRANJE STEKA ====" << endl;

	Osoba* p21 = new Osoba(21, "p21");
	Osoba* p22 = new Osoba(22, "p22");
	Osoba* p23 = new Osoba(23, "p23");
	Osoba* p24 = new Osoba(24, "p24");
	Osoba* p25 = new Osoba(25, "p25");

	stek->dodaj(p21);
	stek->print();

	stek->dodaj(p22);
	stek->print();

	Osoba* pOsoba1 = stek->ukloni();
	stek->print();
	cout << " uklonjeno sa vrha {" << *pOsoba1 << "} " << endl;

	stek->dodaj(p23);
	stek->print();

	stek->dodaj(p24);
	stek->print();

	stek->dodaj(p25);
	stek->print();

	while (!stek->isPrazan())
	{
		Osoba* pOsobaW = stek->ukloni();
		stek->print();
		cout << " uklonjeno sa vrha {" << *pOsobaW << "} " << endl;
	}
}


void _test_V02()
{
	napuniPodatke(new StekPov<Osoba*>);
	napuniPodatke(new StekSekv<Osoba*>);
}
