#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"

using namespace std;


template <typename E> // quick-sort S
void QuickSort(std::vector<E>& S) {
	if (S.size() <= 1) return; // already sorted
	QuickSortStep(S, 0, S.size()-1); // call sort utility
}

/* Quicksort sortuj¹cy czêœæ tablicy zdefiniowan¹ w procentach przez parametr 'proc' */
template <typename E> // quick-sort S
void QuickSort_proc(std::vector<E>& S,double proc) {
	if (S.size() <= 1) return; // already sorted
	//cout <<endl<<S.size()<<"; size "<< size << ";  " << 0.75 * size << endl;
	QuickSortStep(S, 0, (S.size() - 1)*(proc/100)); // call sort utility
}

template <typename E>
void QuickSortStep(std::vector<E>& S, int a, int b) {
	if (a >= b) return; // 0 or 1 left? done
	E pivot = S[b]; // select last as pivot
	int l = a; // left edge
	int r = b - 1; // right edge
	while (l <= r) {
		while (l <= r && ( S[l] <= pivot)) l++; // scan right till larger
		while (r >= l && (S[r] >= pivot)) r--; // scan left till smaller
		if (l < r) // both elements found
			std::swap(S[l], S[r]);
	} // until indices cross
	std::swap(S[l], S[b]); // store pivot at l
	QuickSortStep(S, a, l - 1); // recur on both sides
	QuickSortStep(S, l + 1, b);
}