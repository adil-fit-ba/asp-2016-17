#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "Cvor.h"
#include "Osoba.h"

void _test_V00()
{
	cout << "\n=====TESTIRANJE CVOROVA====" << endl;

	//TESTIRANJE CVOR tipa INT
	Cvor<int>* cInt1 = new Cvor<int>(5, nullptr);
	Cvor<int>* cInt2 = new Cvor<int>(3, cInt1);

	//TESTIRANJE CVOR tipa FLOAT
	Cvor<float>* pFloat1 = new Cvor<float>(2.4, nullptr);
	Cvor<float>* pFloat2 = new Cvor<float>(4.2, pFloat1);
	Cvor<float>* pFloat3 = new Cvor<float>(5.6, pFloat2);

	Osoba o1(1623, "M. Hadzic");
	Osoba o2(2369, "I. Beslic");
	Osoba o3(2954, "E. Mesic");

	//TESTIRANJE CVOR tipa OSOBA
	Cvor<Osoba>* cOsoba1 = new Cvor<Osoba>(o1, nullptr);
	Cvor<Osoba>* cOsoba2 = new Cvor<Osoba>(o2, cOsoba1);
	Cvor<Osoba>* cOsoba3 = new Cvor<Osoba>(o3, cOsoba2);

	Osoba* p1 = new Osoba(1623, "M. Hadzic");
	Osoba* p2 = new Osoba(2369, "I. Beslic");
	Osoba* p3 = new Osoba(2954, "E. Mesic");


	//TESTIRANJE CVOR tipa OSOBA*
	Cvor<Osoba*>* cOsobap1 = new Cvor<Osoba*>(p1, nullptr);
	Cvor<Osoba*>* cOsobap2 = new Cvor<Osoba*>(p2, cOsobap1);
	Cvor<Osoba*>* cOsobap3 = new Cvor<Osoba*>(p3, cOsobap2);
}