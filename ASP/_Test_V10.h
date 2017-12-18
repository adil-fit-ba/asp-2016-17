#pragma once

#include <iostream>
#include "DijkstraAlgoritam.h"
using namespace std;


void _test_V10()
{
	MatricaSusjedstva* M = new MatricaSusjedstva(10);
	M->ucitajMatricu("Matrica10_t.txt");

	DijkstraAlgoritam::start(M, 4, 0)->print("", "\n");


	system("pause");
}
