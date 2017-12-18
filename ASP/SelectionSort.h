#pragma once

template <class Tip>
class SelectionSort
{
public:

	void static sortiraj(ListaSekv<Tip>& niz)
	{
		int i, j, minIndex, pom;
		for (i = 0; i < niz.count() - 1; i++)
		{
			minIndex = i;
			for (j = i + 1; j < niz.count(); j++)
				if (niz[j] < niz[minIndex])
					minIndex = j;
			if (minIndex != i)
			{
				pom = niz[i];
				niz[i] = niz[minIndex];
				niz[minIndex] = pom;
			}
		}

		cout << "Selection sort: sortiranje zavrseno" << endl;
	}
};
