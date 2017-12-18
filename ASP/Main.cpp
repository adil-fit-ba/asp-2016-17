#include <iostream>
using namespace std;

#include "_Test_V00.h"
#include "_Test_V01.h"
#include "_Test_V02.h"
#include "_Test_V03.h"
#include "_Test_V04.h"
#include "_Test_V05.h"
#include "_Test_V06.h"
#include "_Test_V07.h"
#include "_Test_V08.h"
#include "_Test_V09.h"
#include "_Test_V10.h"
#include "_Test_V11.h"
#include "_Test_V12.h"


void main()
{
	string u = "";
	do
	{
		cout << "0: Cvor" << endl;
		cout << "1: ATP Lista" << endl;
		cout << "2: ATP Stek" << endl;
		cout << "3: ATP Red" << endl;
		cout << "4: ATP Prioritetni red" << endl;
		cout << "5: Algoritmi sortiranja n^2 (SelectionSort i InsertionSort)" << endl;
		cout << "6: Algoritmi sortiranja n*logn (QuckSort i MergeSort)" << endl;
		cout << "7: Matrica susjedstva" << endl;
		cout << "8: Binary Search Tree (konstrukcija, pretraga) i Binary Tree obilazak" << endl;
		cout << "9: Algoritmi za obilazak grafa (Bfs i Dfs)" << endl;
		cout << "10: Algoritmi najkrace putanje (Dijkstra) " << endl;
		cout << "11: Algoritmi stabla minimalnog raspona (Prim i Kruskal)" << endl;
		cout << "12: Hashing" << endl;


		cout << "x: IZLAZ" << endl;
		cin >> u;

		if (u=="0") _test_V00();
		if (u=="1") _test_V01();
		if (u=="2") _test_V02();
		if (u=="3") _test_V03();
		if (u=="4") _test_V04();
		if (u=="5") _test_V05();
		if (u=="6") _test_V06();
		if (u=="7") _test_V07();
		if (u=="8") _test_V08();
		if (u=="9") _test_V09();
		if (u=="10")_test_V10();
		if (u=="11")_test_V11();
		if (u=="12")_test_V12();
	} while (u != "x");
	
	system("pause");
}
