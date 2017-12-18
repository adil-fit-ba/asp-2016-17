#pragma once

#include <iostream>
#include "BfsAlgoritamIterativno.h"
#include "DfsAlgoritamIterativno.h"
#include "DfsAlgoritamRekurzija.h"
using namespace std;





void _test_V09()
{
	
	MatricaSusjedstva* M = new MatricaSusjedstva(9);

	M->ucitajMatricu("Matrica9.txt");
	cout << endl << "Unesena je sljedeca matrica susjedstva : " << endl;
	M->ispisMatrice();

	cout << endl << "DFS (rekurzija): " << endl;
	DfsAlgoritamRekurzija::start(M, 0)->print();

	cout << endl << "DFS (iterativno, stek): " << endl;
	DfsAlgoritamIterativno::start(M, 0)->print();

	cout << endl << "BFS (iterativno, red): " << endl;
	BfsAlgoritamIterativno::start(M, 0)->print();


	cout << endl;
	system("pause");
}

