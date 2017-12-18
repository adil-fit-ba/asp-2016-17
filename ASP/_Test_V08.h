#pragma once

#include <iostream>
#include "BinarnoStablo.h"
#include "BSObilazak.h"
using namespace std;


void _test_V08()
{
	BinarnoStabloZaPretrazivanje<int> stablo;

	for (int i = 0; i <10; i++)
	{
		int r = rand() % 100;
		stablo.dodaj(r);
		cout << "Dodata je vrijednos " << r << endl;
	}

	cout << "BFS PreOrder (rekurzija): " << endl;
	BSObilazak<int>::PreOrder_R(stablo)->print();

	cout << "BFS PreOrder (iterativno, stek): " << endl;
	BSObilazak<int>::PreOrder_I(stablo)->print();

	cout << "BFS PostOrder (rekurzija): " << endl;
	BSObilazak<int>::PostOrder_R(stablo)->print();	

	cout << "BFS PostOrder (iterativno, stek): " << endl;
	BSObilazak<int>::PostOrder_I(stablo)->print();


	cout << "BFS InOrder (rekurzija): " << endl;
	BSObilazak<int>::InOrder_R(stablo)->print();
	
	cout << "BFS InOrder (iterativno, stek): " << endl;
	BSObilazak<int>::InOrder_I(stablo)->print();

	
	cout << "DFS-Nivo po nivo (iterativno, red): " << endl;
	BSObilazak<int>::NivoPoNivo_I(stablo)->print();

	cout << "Trazi vrijednost: " << endl;
	int x;
	cin >> x;

	BSCvor<int>* cvor = stablo.trazi(x);
	if (cvor != nullptr)
		cout << "Vrijednost je pronadjena " << endl;
	else
		cout << "Vrijednost nije pronadjena " << endl;

	system("pause");
}
