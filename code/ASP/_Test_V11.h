#pragma once

#include <iostream>
#include "PrimAlgoritam.h"
#include "KruskalAlgoritam.h"
using namespace std;


void _test_V11()
{
	MatricaSusjedstva* M = new MatricaSusjedstva(9);
	M->ucitajMatricu("Matrica9_t.txt");
	M->ispisMatrice();

	KruskalAlgoritam::start(M)->print();
	PrimAlgoritam::start(M)->print();
	

	system("pause");
}
