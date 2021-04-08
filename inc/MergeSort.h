#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"
#include "Exchange.h"
using namespace std;


template <typename E> // merge-sort S
void MergeSort(vector<E>& S/*, const C& less*/) {
	typedef vector<E> vect;
	int n = S.size();
	vect v1(S); vect* in = &v1; // initial input vector
	vect v2(n); vect* out = &v2; // initial output vector
	for (int m = 1; m < n; m *= 2) { // list sizes doubling
		for (int b = 0; b < n; b += 2 * m) { // beginning of list
			Merge(*in, *out, b, m); // merge sublists
		}
		std::swap(in, out); // swap input with output
	}
	S = *in; // copy sorted array to S
}



// merge in[b. .b+m-1] and in[b+m. .b+2*m-1]
template <typename E/*, typename C*/>
void Merge(vector<E>& in, vector<E>& out, int b, int m) {
	int i = b; // index into run #1
	int j = b + m; // index into run #2
	int n = in.size();
	int e1 = std::min(b + m, n); // end of run #1
	int e2 = std::min(b + 2 * m, n); // end of run #2
	int k = b;
	while ((i < e1) && (j < e2)) {
		if (!(in[j] <= in[i])) // append smaller to S
		{
			out[k++] = in[i++];
		}
		else
		{
			out[k++] = in[j++];
		}
	}
	while (i < e1) { // copy rest of run 1 to S
		out[k++] = in[i++];
	}
	while (j < e2) { // copy rest of run 2 to S
		out[k++] = in[j++];
	}
}




/* tablice  */
template <typename E> // quick-sort S
void MergeSort(E* tab, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		MergeSort(tab, l, m);
		MergeSort(tab, m + 1, r);
		Merge(tab, l, m, r);
	}
}

template <typename E>
void Merge(E* tab, int l, int m, int r)
{
	int lSize = m - l + 1;
	int rSize = r - m;

	//Tablice pomocnicze
	E* tabL = new int[lSize];
	E* tabR = new int[rSize];

	// Kopiowanie danych do tablic pomocniczych
	for (int x = 0; x < lSize; x++)
		tabL[x] = tab[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];

	int indexL = 0;
	int indexR = 0;
	int currIndex;

	//£¹czenie tablic R i L
	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++)
	{
		if (tabL[indexL] <= tabR[indexR])
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}

	//Jeœli w tablicy tabL pozosta³y jeszcze jakieœ elementy
	//kopiujemy je
	while (indexL < lSize)
		tab[currIndex++] = tabL[indexL++];

	//Jeœli w tablicy tabR pozosta³y jeszcze jakieœ elementy
	//kopiujemy je
	while (indexR < rSize)
		tab[currIndex++] = tabR[indexR++];

	delete[] tabL;
	delete[] tabR;
}



