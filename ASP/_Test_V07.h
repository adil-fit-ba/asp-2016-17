#pragma once


#include <iostream>
#include "MatricaSusjedstva.h"
using namespace std;


void _test_V07()
{
	MatricaSusjedstva M(4);
	M.ucitajMatricu("Matrica4.txt");
	M.ispisMatrice();

	cout << (M.provjera() ? "Matrica je ispravna" : "Matrica nije ispravna") << endl;;
	cout << "Izlazni stepen za vrh 0 je " << M.izlazniStepen(0) << endl;
	cout << "Ulazni stepen za vrh 0 je " << M.ulazniStepen(0) << endl;

	cout << "Spammeri su: ";
	M.izlazniStepenMax()->print();
	cout << endl;

	cout << "Izlazni susjedi za vrh 0 su: ";
	M.susjediTo(0)->print();
	cout << endl;


	for (int i = 0; i < M.velicina; i++)
	{
		cout << "vrh " << i << ": ";
		M.susjediTo(i)->print();
	}

	system("pause");
}
