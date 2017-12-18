#pragma once

#include <iostream>

#include "RedPov.h"
#include "RedSekv.h"
#include "ListaPov.h"
#include "ListaSekv.h"
using namespace std;

class BfsAlgoritamIterativno
{
private:
	int starVrh;
	MatricaSusjedstva* M;

	BfsAlgoritamIterativno(MatricaSusjedstva* M, int starVrh)
	{
		this->M = M;
		this->starVrh = starVrh;
		//privatni konstruktor "zabranjuje" instanciranje ove klase izvan ove klase, tj. jedini način instaniranja ove klase je preko public static funkcije koja se nalazi u ovoj klasi
	}

	Lista<int>* _start()
	{
		this->M = M;
		Lista<int>* posjecen = new ListaSekv<int>(M->velicina);

		RedPov<int> red;

		//dodaj početni vrh u stek
		red.dodaj(starVrh);

		while (!red.isPrazan())
		{
			int v = red.ukloni();

			if (!posjecen->sadrzi(v))
			{
				posjecen->dodaj(v);

				for (int i = 0; i < M->velicina; i++)
				{
					//ako je vrh "i" susjed
					if (M->isSusjed(v, i))
					{
						//dodatno opcionalno poboljšanje: "!red.sadrzi(i)"
						if (!red.sadrzi(i) && !posjecen->sadrzi(i))
							red.dodaj(i);
					}
				}
			}
		}

		return posjecen;
	}

public:
	static Lista<int>* start(MatricaSusjedstva* M, int startVrh = 0)
	{
		return BfsAlgoritamIterativno(M, startVrh)._start();
	}
};