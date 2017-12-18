#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Ivica
{
	/*
		Ova klasa se koristi u V11_MstAlgoritmi
	*/
	int startVrh;
	int endVrh;
	int tezina;
public:
	Ivica()
	{

	}
	Ivica(int startVrh, int endVrh, int tezina)
	{
		this->startVrh = startVrh;
		this->endVrh = endVrh;
		this->tezina = tezina;
	}
	friend ostream& operator<<(ostream& o, Ivica* i)
	{
		return operator<<(o,*i);
	}
	friend ostream& operator<<(ostream& o, Ivica& i)
	{
		o << "t(" << i.startVrh << "," << i.endVrh << ") = " << i.tezina;
		return o;
	}

	friend bool operator>(Ivica& left, Ivica& right)
	{
		return left.tezina < right.tezina;
	}
};

