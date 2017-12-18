#pragma once

#include <iostream>

#include "StekSekv.h"
#include "ListaPov.h"
#include "ListaSekv.h"
using namespace std;

class DfsAlgoritamIterativno
{
private:
	int starVrh;
	MatricaSusjedstva* M;

	DfsAlgoritamIterativno(MatricaSusjedstva* M, int starVrh)
	{
		this->M = M;
		this->starVrh = starVrh;
		//privatni konstruktor "zabranjuje" instanciranje ove klase izvan ove klase, tj. jedini naèin instaniranja ove klase je preko public static funkcije koja se nalazi u ovoj klasi
	}

	Lista<int>* _start()
	{
		this->M = M;
		Lista<int>* posjecen = new ListaSekv<int>(M->velicina);

		StekPov<int> stek;

		stek.dodaj(starVrh);

		while (!stek.isPrazan())
		{
			int v = stek.ukloni();
			
			if (!posjecen->sadrzi(v))
			{
				posjecen->dodaj(v);

				for (int i = M->velicina - 1; i >= 0; i--)
				{
					if (M->isSusjed(v, i))
					{
						if (!posjecen->sadrzi(i))
							stek.dodaj(i);
					}
				}
			}
		}
		
		return posjecen;
	}

public:
	static Lista<int>* start(MatricaSusjedstva* M, int starVrh = 0)
	{
		return DfsAlgoritamIterativno(M, starVrh)._start();
	}
};