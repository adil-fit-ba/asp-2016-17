#pragma once

#include "ListaSekv.h"

template <class Tip>
class MergeSort
{
	void static Merge(ListaSekv<Tip>& tempNiz, ListaSekv<Tip>& elementNiz, const int list1, const int size1, const int list2, const int size2)
	{
		int i = list1, j = list2, k = list1;

		while (i < list1 + size1 && j < list2 + size2)
		{
			if (tempNiz[i] < tempNiz[j])
				elementNiz[k++] = tempNiz[i++];
			else
				elementNiz[k++] = tempNiz[j++];
		}

		while (i < list1 + size1)
			elementNiz[k++] = tempNiz[i++];
		while (j < list2 + size2)
			elementNiz[k++] = tempNiz[j++];
		for (k = list1; k < list1 + size1 + size2; k++)
			tempNiz[k] = elementNiz[k];
	}

	void static Rastavi(ListaSekv<Tip>& tempNiz, ListaSekv<Tip>& elementNiz, const int list1, const int size)
	{
		int list2, size1, size2;

		if (size > 1)
		{
			list2 = list1 + size / 2;
			size1 = list2 - list1;
			size2 = size - size1;
			Rastavi(tempNiz, elementNiz, list1, size1);
			Rastavi(tempNiz, elementNiz, list2, size2);
			Merge(tempNiz, elementNiz, list1, size1, list2, size2);
		}
	}

public:

	void static sortiraj(ListaSekv<Tip>& elementNiz)
	{
		ListaSekv<Tip> tempNiz(elementNiz, elementNiz.count());

		Rastavi(elementNiz, tempNiz, 0, elementNiz.count());

		cout << "Merge sort: sortiranje zavrseno" << endl;
	}
};




