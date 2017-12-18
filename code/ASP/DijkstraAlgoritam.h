#pragma once

#include <iostream>

#include "ListaSekv.h"
#include "Ivica.h"
#include "set"
using namespace std;


class DijkstraAlgoritam
{
	/**
		modifikovana verzija http://cs.fit.edu/~ryan/java/programs/graph/Dijkstra-java.html
	*/
private:
	MatricaSusjedstva* M;

	int* dist;
	int* pred;
	bool* posjecen;

	int startVrh;
	int endVrh;

	DijkstraAlgoritam(MatricaSusjedstva* M, int startVrh, int endVrh)
	{
		this->M = M;

		this->dist = new int[M->velicina];
		this->pred = new int[M->velicina];
		this->posjecen = new bool[M->velicina];

		this->startVrh = startVrh;
		this->endVrh = endVrh;
		//privatni konstruktor "zabranjuje" instanciranje ove klase izvan ove klase, tj. jedini naèin instaniranja ove klase je preko public static funkcije koja se nalazi u ovoj klasi
	}

	int minNeposjecenVrh() 
	{
		int minDist = INT_MAX;
		int minVrh = -1;   // nije povezan
		for (int i = 0; i < M->velicina; i++) 
		{
			if (!posjecen[i] && dist[i] < minDist)
			{
				minVrh = i;
				minDist = dist[i];
			}
		}
		return minVrh;
	}

	ListaSekv<Ivica*>* _start()
	{

		cout << "startVrh: " << startVrh << ", endVrh: " << endVrh << endl;

		ListaSekv<Ivica*>* rezultat = new ListaSekv <Ivica*>;

		for (int i = 0; i < M->velicina; i++)
		{
			dist[i] = INT_MAX;
			posjecen[i] = false;
		}
		dist[startVrh] = 0;
		//==========================

		for (int i = 0; i < M->velicina; i++)
		{
			int nVrh = minNeposjecenVrh();
			posjecen[nVrh] = true;

			int nDist = dist[nVrh];
			for (int sVrh = 0; sVrh < M->velicina; sVrh++)
			{
				if (M->isSusjed(nVrh, sVrh))
				{
					int nsTezina = M->tezina(nVrh, sVrh);

					int xDist = nDist + nsTezina;

					if (xDist < dist[sVrh])
					{
						dist[sVrh] = xDist;
						pred[sVrh] = nVrh;
					}

				}
			}
		}

		int putDistanca = 0;
		int w = endVrh;
		while (w != startVrh)
		{
			int p = pred[w];
			int tezina = M->tezina(p, w);
			rezultat->dodaj(new Ivica(p, w, tezina));
			putDistanca += tezina;
			w = p;
		}
		cout << "Ukupna distanca je: " << putDistanca << endl;

		return rezultat;
	}

public:
	static Lista<Ivica*>* start(MatricaSusjedstva* M, int startVrh, int endVrh)
	{
		return DijkstraAlgoritam(M, startVrh, endVrh)._start();
	}

};

