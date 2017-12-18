#pragma once

template <class Tip>
class InsertionSort
{
public:
	void static sortiraj(ListaSekv<Tip>& niz)
	{
		
		for (int i = 1; i < niz.count(); i++)
		{
			int j = i;
			while (j > 0 && niz[j - 1] > niz[j])
			{
				int pom = niz[j];
				niz[j] = niz[j - 1];
				niz[j - 1] = pom;
				j--;
			}
		}
		cout << "Insertion sort: sortiranje zavrseno" << endl;
	}
};
