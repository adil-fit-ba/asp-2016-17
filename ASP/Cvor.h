#pragma once

#include <iostream>
using namespace std;

template <class Tip>
struct Cvor
{
	Cvor* next;
	Tip info;
	
	Cvor(Tip info, Cvor<Tip>* next) : info(info)
	{
		this->next = next;
	}
};
