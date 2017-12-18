#pragma once

#include <iostream>
#include "ListaSekv.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
using namespace std;


void _test_V05()
{
	int A[] = { 5, 8, 1, 3, 9, 7, 25 };

	ListaSekv<int> lista(A, 7);

	cout << "Nesortirani niz" << endl;
	lista.print();

	cout << "1: Insertion sort\n";
	cout << "2: Selection sort\n";
	cout << "odabir ---> ";

	int u;
	cin >> u;

	if (u == 1)
		InsertionSort<int>::sortiraj(lista);

	if (u == 2)
		SelectionSort<int>::sortiraj(lista);

	lista.print();

	system("pause");
}
