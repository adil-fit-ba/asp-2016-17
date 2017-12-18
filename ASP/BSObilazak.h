
#pragma once

#include "BinarnoStablo.h"
#include "ListaPov.h"
#include "StekPov.h"


template <class Kljuc>
class BSObilazak
{
	BSObilazak()
	{
		//privatni konstruktor "zabranjuje" instanciranje ove klase
	}

	static void rekurzija_PostOrder(BSCvor<Kljuc>* &cvor, Lista<Kljuc>* lista)
	{
		if (cvor != nullptr)
		{
			rekurzija_PostOrder(cvor->lijevoDijete, lista);
			rekurzija_PostOrder(cvor->desnoDijete, lista);
			lista->dodaj(cvor->value);
		}
	}

	static void rekurzija_InOrder(BSCvor<Kljuc>* &cvor, Lista<Kljuc>* lista)
	{
		if (cvor != nullptr)
		{
			rekurzija_InOrder(cvor->lijevoDijete, lista);
			lista->dodaj(cvor->value);
			rekurzija_InOrder(cvor->desnoDijete, lista);
		}
	}

	static void rekurzija_PreOrder(BSCvor<Kljuc>* &cvor, Lista<Kljuc>* lista)
	{
		if (cvor != nullptr)
		{
			lista->dodaj(cvor->value);
			rekurzija_PreOrder(cvor->lijevoDijete, lista);
			rekurzija_PreOrder(cvor->desnoDijete, lista);
		}
	}

public:

	static Lista<Kljuc>* PostOrder_R(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{
		Lista<Kljuc>* lista = new ListaPov < Kljuc > ;
		rekurzija_PostOrder(stablo.korijen, lista);
		return lista;
	}

	static Lista<Kljuc>* PreOrder_R(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{
		Lista<Kljuc>* lista = new ListaPov < Kljuc > ;
		rekurzija_PreOrder(stablo.korijen, lista);
		return lista;
	}

	static Lista<Kljuc>*  InOrder_R(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{
		Lista<Kljuc>* lista = new ListaPov<Kljuc> ;
		rekurzija_InOrder(stablo.korijen, lista);
		return lista;
	}


	static Lista<Kljuc>* PreOrder_I(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{
		
		Lista<Kljuc>* lista = new ListaPov<Kljuc>;

		StekPov<BSCvor<Kljuc>*> stek;
		stek.dodaj(stablo.korijen);

		while (!stek.isPrazan())
		{
			BSCvor<Kljuc>* cvor = stek.ukloni();


			lista->dodaj(cvor->value);

			if (cvor->desnoDijete != nullptr)
				stek.dodaj(cvor->desnoDijete);

			if (cvor->lijevoDijete != nullptr)
				stek.dodaj(cvor->lijevoDijete);
		}

		return lista;
	}

	static Lista<Kljuc>* NivoPoNivo_I(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{

		Lista<Kljuc>* lista = new ListaPov<Kljuc>;
		
		RedPov<BSCvor<Kljuc>*> red;
		red.dodaj(stablo.korijen);

		while (!red.isPrazan())
		{
			BSCvor<Kljuc>* cvor = red.ukloni();

			lista->dodaj(cvor->value);

			if (cvor->lijevoDijete != nullptr)
				red.dodaj(cvor->lijevoDijete);

			if (cvor->desnoDijete != nullptr)
				red.dodaj(cvor->desnoDijete);
		}

		return lista;
	}

	static Lista<Kljuc>* InOrder_I(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{
		/*
			http://articles.leetcode.com/2010/04/binary-search-tree-in-order-traversal.html

			Može biti na ispitu za šk. go. 2016/17.
		*/
		Lista<Kljuc>* lista = new ListaPov<Kljuc>;

		BSCvor<Kljuc>* current = stablo.korijen;

		StekPov<BSCvor<Kljuc>*> stek;

		while (true)
		{
			if (current != nullptr)
			{
				stek.dodaj(current);
				current = current->lijevoDijete;
			}
			else
			{
				if (stek.isPrazan())
					break;

				current = stek.ukloni();
				lista->dodaj(current->value);
				current = current->desnoDijete;
			}
		}
		return lista;
	}

	static Lista<Kljuc>* PostOrder_I(BinarnoStabloZaPretrazivanje<Kljuc> &stablo)
	{
		/*
			http://articles.leetcode.com/2010/10/binary-tree-post-order-traversal.html
			Može biti na ispitu za šk. go. 2016/17.
		*/
		Lista<Kljuc>* lista = new ListaPov<Kljuc>;
		Stek<Kljuc>* rezultat = new StekPov<Kljuc>;

		StekPov<BSCvor<Kljuc>*> stek;
		stek.dodaj(stablo.korijen);

		while (!stek.isPrazan())
		{
			BSCvor<Kljuc>* cvor = stek.ukloni();
			if (cvor != nullptr)
			{
				rezultat->dodaj(cvor->value);
				stek.dodaj(cvor->lijevoDijete);
				stek.dodaj(cvor->desnoDijete);
			}
		}

		while (!rezultat->isPrazan())
		{
			lista->dodaj(rezultat->ukloni());
		}

		return lista;
	}


};