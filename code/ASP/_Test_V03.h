#pragma once

#include <iostream>
#include "RedPov.h"
#include "RedSekv.h"
#include "Osoba.h"
using namespace std;



void napuniPodatke(Red<Osoba*>* red)
{
	cout << "\n=====TESTIRANJE REDA ====" << endl;

	Osoba* p21 = new Osoba(21, "p21");
	Osoba* p22 = new Osoba(22, "p22");
	Osoba* p23 = new Osoba(23, "p23");
	Osoba* p24 = new Osoba(24, "p24");
	Osoba* p25 = new Osoba(25, "p25");

	red->dodaj(p21);
	red->print();

	red->dodaj(p22);
	red->print();

	Osoba* pOsoba1 = red->ukloni();
	red->print();
	cout << "RED: uklonjen sa pocetka {" << *pOsoba1 << "} " << endl;

	red->dodaj(p23);
	red->print();

	red->dodaj(p24);
	red->print();

	red->dodaj(p25);
	red->print();

	while (!red->isPrazan())
	{
		Osoba* pOsobaW = red->ukloni();
		red->print();
		cout << " uklonjeno sa pocetka {" << *pOsobaW << "} " << endl;
	}
}


void _test_V03()
{
	napuniPodatke(new RedSekv<Osoba*>);
	napuniPodatke(new RedPov<Osoba*>);	
}
