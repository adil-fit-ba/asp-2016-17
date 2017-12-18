#pragma once
#include "Hashiranje.h"
#include "HashiranjeUlancavanjem.h"
#include "HashiranjeOtvorenoAdresiranje.h"

void testHashing(Hashiranje<int>* h1)
{
	h1->dodaj(23);
h1->dodaj(25);
h1->dodaj(2245);
h1->dodaj(145);
h1->dodaj(145);
h1->dodaj(6452);
h1->dodaj(1453);
h1->dodaj(1451);
h1->print();
cout << "===============" << endl;
h1->ukloni(2245);
h1->print();
}

void _test_V12()
{
	testHashing(new HeshiranjeOtvorenoAdresiranje<int>());
	testHashing(new HeshiranjeUlancavanjem<int>());
}
