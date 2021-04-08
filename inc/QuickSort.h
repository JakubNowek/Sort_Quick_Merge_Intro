#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"
#include "Exchange.h"
using namespace std;

/* Wektory */

/* QuickSort dla wektorów sortuj¹cy min->max*/
///* Quicksort sortuj¹cy tablicê lub czêœæ tablicy zdefiniowan¹ w procentach przez parametr 'proc' */
template <typename E> // quick-sort S
void QuickSort(std::vector<E>& S, double proc) {
	if (S.size() <= 1) return; // already sorted
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

/* QuickSort dla wektorów sortuj¹cy max->min*/
///* Quicksort sortuj¹cy tablicê lub czêœæ tablicy zdefiniowan¹ w procentach przez parametr 'proc' */
template <typename E> // quick-sort S
void _backQuickSort(std::vector<E>& S, double proc) {
	if (S.size() <= 1) return; // already sorted
	_backQuickSortStep(S, 0, (S.size() - 1) * (proc / 100)); // call sort utility
}

template <typename E>
void _backQuickSortStep(std::vector<E>& S, int a, int b) {
	if (a >= b) return; // 0 or 1 left? done
	E pivot = S[b]; // select last as pivot
	int l = a; // left edge
	int r = b - 1; // right edge
	while (l <= r) {
		while (l <= r && (S[l] >= pivot)) l++; // scan right till larger
		while (r >= l && (S[r] <= pivot)) r--; // scan left till smaller
		if (l < r) // both elements found
			std::swap(S[l], S[r]);
	} // until indices cross
	std::swap(S[l], S[b]); // store pivot at l
	_backQuickSortStep(S, a, l - 1); // recur on both sides
	_backQuickSortStep(S, l + 1, b);
}


/* Tablice */

/* Quicksort dla tablic** sortuj¹cy min->max */
/* Quicksort sortuj¹cy tablicê lub czêœæ tablicy zdefiniowan¹ w procentach przez parametr 'proc' */
template <typename E> // quick-sort S
void QuickSort(E* S, int size, double proc) {
	if (size <= 1) return; // already sorted
	QuickSortStep(S, 0, (size-1) * (proc / 100)); // call sort utility
}

template <typename E>
void QuickSortStep(E* S, int a, int b) {
	if (a >= b) return; // 0 or 1 left? done
	E pivot = S[b]; // select last as pivot
	int l = a; // left edge
	int r = b - 1; // right edge
	while (l <= r) {
		while (l <= r && (S[l] <= pivot)) l++; // scan right till larger
		while (r >= l && (S[r] >= pivot)) r--; // scan left till smaller
		if (l < r) // both elements found
			Exchange(S,l,r);
	} // until indices cross
	Exchange(S,l,b); // store pivot at l
	QuickSortStep(S, a, l - 1); // recur on both sides
	QuickSortStep(S, l + 1, b);
}

/*Quicksort dla tablic** sortuj¹cy max->min */
/* Quicksort sortuj¹cy tablicê lub czêœæ tablicy zdefiniowan¹ w procentach przez parametr 'proc' */
template <typename E> // quick-sort S
void _backQuickSort(E* S, int size, double proc) {
	if (size <= 1) return; // already sorted
	QuickSortStep(S, 0, (size-1) * (proc / 100)); // call sort utility
}

template <typename E>
void _backQuickSortStep(E* S, int a, int b) {
	if (a >= b) return; // 0 or 1 left? done
	E pivot = S[b]; // select last as pivot
	int l = a; // left edge
	int r = b - 1; // right edge
	while (l <= r) {
		while (l <= r && (S[l] >= pivot)) l++; // scan right till larger // jeœli mamy > to sortuje malej¹co, jeœli <  to rosn¹co
		while (r >= l && (S[r] <= pivot)) r--; // scan left till smaller // jeœli mamy < to sortuje malej¹co, jeœli >  to rosn¹co
		if (l < r) // both elements found
			Exchange(S,l,r);
	} // until indices cross
	Exchange(S,l,b); // store pivot at l
	_backQuickSortStep(S, a, l - 1); // recur on both sides
	_backQuickSortStep(S, l + 1, b);
}