#pragma once


#include <iostream>
#include <string>

using namespace std;

#include "Osoba.h"
#include "Lista.h"
#include "ListaSekv.h"
#include "ListaPov.h"


void napuniPodatke(Lista<Osoba*>* lista)
{
	cout << "\n=====TESTIRANJE LISTE tipa OSOBA*	====" << endl;

	Osoba* p21 = new Osoba(21, "p21");
	Osoba* p22 = new Osoba(22, "p22");
	Osoba* p23 = new Osoba(23, "p23");
	Osoba* p24 = new Osoba(24, "p24");
	Osoba* p25 = new Osoba(25, "p25");

	lista->dodaj(p21);
	lista->dodaj(p22);

	Osoba* pPrvi = lista->ukloni();
	cout << "LISTA: uklonjen {" << *pPrvi << "} " << endl;

	lista->dodaj(p23);
	lista->dodaj(p24);
	lista->dodaj(p25);

	cout << "lista[0] = " << lista->get(0) << endl;
	cout << "lista[1] = " << lista->get(1) << endl;
	cout << "lista[2] = " << lista->get(2) << endl;

	while (!lista->isPrazan())
	{
		Osoba* pPoslj = lista->ukloni();
		cout << "LISTA: uklonjen {" << *pPoslj << "} " << endl;
	}
}


void _test_V01()
{
	napuniPodatke(new ListaSekv<Osoba*>);
	napuniPodatke(new ListaPov<Osoba*>);
}