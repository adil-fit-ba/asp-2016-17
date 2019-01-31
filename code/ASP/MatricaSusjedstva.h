#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "ListaPov.h"
#include "ListaSekv.h"
#include "Ivica.h"
using namespace std;


class MatricaSusjedstva
{
	int** data;
public:
	const int velicina;

	MatricaSusjedstva(int v) : velicina(v)
	{
		data = new int*[v];
		for (int i = 0; i < v; i++)
		{
			data[i] = new int[v];
			for (int j = 0; j < v; j++)
			{
				data[i][j] = 0;
			}
		}
	}

	void ucitajMatricu(string filename) 
	{
		ifstream fin(filename);

		for (int i = 0; i < velicina; i++)
		{
			for (int j = 0; j < velicina; j++)
			{
				int u;
				fin >> u;
				data[i][j] = u;
			}
		}

		fin.close();
	}

	void ispisMatrice()
	{
		for (int i = 0; i < velicina; i++)
		{
			for (int j = 0; j < velicina; j++)
			{
				cout << data[i][j] << "\t";
			}
			cout << endl;
		}
	}

	bool provjera() 
	{
		for (int i = 0; i < velicina; i++)
		{
			if (data[i][i] != 0)
				return false;
		}
		return true;
	}

	int izlazniStepen(int i)
	{
		int suma = 0;
		for (int j = 0; j < velicina; j++)
		{
			suma += data[i][j];
		}
		return suma;
	}

	int ulazniStepen(int j)
	{
		int suma = 0;
		for (int i = 0; i < velicina; i++)
		{
			suma += data[i][j];
		}

		return suma;
	}


	ListaSekv<int>* susjediTo(int i)
	{
		ListaSekv<int>* x = new ListaSekv<int>;

		for (int j = 0; j < velicina; j++)
		{
			if (data[i][j] != 0)
				x->dodaj(j);
		}
		
		return x;
	}

	ListaSekv<int>* susjediFrom(int j)
	{
		ListaSekv<int>* x = new ListaSekv<int>;

		for (int i = 0; i < velicina; j++)
		{
			if (isSusjed(i,j))
				x->dodaj(i);
		}

		return x;
	}


	ListaPov<int>* izlazniStepenMax() //O(n2 + 2n)
	{
		//korak1: raèunanje izlaznih stepena O(n2)
		int* stepeni = new int[velicina];
		for (int i = 0; i < velicina; i++)
		{
			stepeni[i] = izlazniStepen(i);
		}

		//korak2: pronaæi maxVr O(n)
		int maxVr = INT_MIN;
		for (int i = 0; i < velicina; i++)
		{
			if (stepeni[i] > maxVr)
				maxVr = stepeni[i];
		}


		//korak3: dodati sve vrhove èiji je izlazni stepen = maxVr
		//O(n)
		ListaPov<int>* x = new ListaPov<int>;
	
		for (int i = 0; i < velicina; i++)
		{
			if (stepeni[i] == maxVr)
				x->dodaj(i);
		}
		return x;
	}

	int tezina(int from, int to)
	{
		return data[from][to];
	}

	bool isSusjed(int from, int to)
	{
		return data[from][to] != 0;
	}

	int najbliziSusjed(int f)
	{
		ListaSekv<int>* susjedi_to = susjediTo(f);

		int minSusjed = -1;
		int minTezina = INT_MAX;

		for (int i = 0; i < susjedi_to->count(); i++)
		{
			int s = susjedi_to->get(i);
			int t = tezina(f, s);
			if (t < minTezina)
			{
				minTezina = t;
				minSusjed = s;
			}
		}

		return minSusjed;
	}

	void dodaj(Ivica * ivica)
	{
		data[ivica->startVrh][ivica->endVrh] = ivica->tezina;
		data[ivica->endVrh][ivica->startVrh] = ivica->tezina;
	}

	
};

