#pragma once

template <class Kljuc>
struct BSCvor
{
	Kljuc value;
	BSCvor* lijevoDijete;
	BSCvor* desnoDijete;

	BSCvor(Kljuc value)
	{
		this->value = value;
		this->lijevoDijete = nullptr;
		this->desnoDijete = nullptr;
	}
};