#pragma once

template <class Tip>
class QuickSort
{
	void static Swap(ListaSekv<Tip> N, const int i, const int j)
	{
		cout << "rotacija: N[i=" << i << "] -> " << N[i] << " i N[j=" << i << "] -> \t" << N[j] << " " << endl;
		if (i != j)
		{
			int temp = N[i];
			N[i] = N[j];
			N[j] = temp;
		}
	}

	void static Rekurzija(ListaSekv<Tip>& N, const int low, const int high)
	{
		if (low < high)
		{
			cout << "\nQuickSort: low=" << low << ", " << "high=" << high << endl;
			int pivotloc = low;
			int pivotkey = N[low];
			for (int i = low + 1; i <= high; i++)
			{
				if (N[i] < pivotkey)
				{
					pivotloc++;
					Swap(N, pivotloc, i);
				}
			}

			Swap(N, low, pivotloc);

			Rekurzija(N, low, pivotloc - 1);
			Rekurzija(N, pivotloc + 1, high);
		}
	}


public:

	void static sortiraj(ListaSekv<Tip>& A)
	{
		Rekurzija(A, 0, A.count() - 1);

		cout << "Quick sort: sortiranje zavrseno" << endl;
	}
};
