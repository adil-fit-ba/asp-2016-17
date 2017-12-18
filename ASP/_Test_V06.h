#pragma once

#include <iostream>
#include "MergeSort.h"
#include "QuickSort.h"
using namespace std;


void _test_V06()
{
	int A[] = { 5, 8, 1, 3, 9, 7, 25 };

	ListaSekv<int> lista(A, 7);

	cout << "Nesortirani niz" << endl;
	lista.print();

	cout << "1: Merge sort\n";
	cout << "2: Quick sort\n";
	cout << "odabir ---> ";

	int u;
	cin >> u;

	if (u == 1)
		MergeSort<int>::sortiraj(lista);

	if (u == 2)
		QuickSort<int>::sortiraj(lista);

	lista.print();

	system("pause");
}
