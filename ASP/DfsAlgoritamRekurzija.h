#pragma once

#include "ListaSekv.h"
#include "MatricaSusjedstva.h"
using namespace std;

class DfsAlgoritamRekurzija
{
private:
	int starVrh;
	MatricaSusjedstva* M;
	Lista<int>* posjecen;

	DfsAlgoritamRekurzija(MatricaSusjedstva* M, int starVrh)
	{
		this->M = M;
		this->posjecen = new ListaSekv<int>;
		this->starVrh = starVrh;

		//privatni konstruktor "zabranjuje" instanciranje ove klase izvan ove klase, tj. jedini naèin instaniranja ove klase je preko public static funkcije koja se nalazi u ovoj klasi
	}

	Lista<int>* _start()
	{
		Rekurzija(starVrh);
		return posjecen;
	}

	void Rekurzija(int v)
	{
		posjecen->dodaj(v);
		for (int i = 0; i < M->velicina; i++)
		{
			if (M->isSusjed(v, i) && !posjecen->sadrzi(i))
				Rekurzija(i);
		}
	}

public:
	static Lista<int>* start(MatricaSusjedstva* M, int starVrh = 0)
	{
		return DfsAlgoritamRekurzija(M, starVrh)._start();
	}
};