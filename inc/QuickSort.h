#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"
#include "Exchange.h"

/*nag³ówki*/

/* Wektory */
/** 
 * min->max
 * @brief funkcja wywo³uj¹ca algorytm quicksort sortuj¹cy wektor lub czêœæ wektora
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param proc - iloœæ pocz¹tkowych elementów, wyra¿ona w %, która ma zosta posortowana
*/
template <typename E> // quick-sort S
void QuickSort(std::vector<E>& S, double proc);

/**
 * @brief funkcja realizuj¹ca algorytm quicksort sortuj¹cy wektor
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param a - zmienna przechowaj¹ca indeks pierwszego elementu wektora który sortujemy
 * @param b - zmienna przechowaj¹ca indeks ostatniego elementu wektora który sortujemy
*/
template <typename E>
void QuickSortStep(std::vector<E>& S, int a, int b);

/**
 * max->min
 * @brief funkcja pomocnicza wywo³uj¹ca algorytm quicksort sortuj¹cy wektor lub czêœæ wektora w kolejnosci malej¹cej
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param proc - iloœæ pocz¹tkowych elementów, wyra¿ona w %, która ma zosta posortowana
*/
template <typename E> // quick-sort S
void _backQuickSort(std::vector<E>& S, double proc);

/**
 * @brief funkcja pomocnicza realizuj¹ca algorytm quicksort sortuj¹cy wektor
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param a - zmienna przechowaj¹ca indeks pierwszego elementu wektora który sortujemy
 * @param b - zmienna przechowaj¹ca indeks ostatniego elementu wektora który sortujemy
*/
template <typename E>
void _backQuickSortStep(std::vector<E>& S, int a, int b);

/* Tablice */
/**
 * @brief funkcja wywo³uj¹ca algorytm quicksort sortuj¹cy tablicê lub czêœæ tablicy
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - tablica do posortowania
 * @param size - zmienna przechowuj¹ca rozmiar tablicy do sortowania
 * @param proc - iloœæ pocz¹tkowych elementów, wyra¿ona w %, która ma zosta posortowana
*/
template <typename E> // quick-sort S
void QuickSort(E* S, int size, double proc);

/**
 * @brief funkcja realizuj¹ca algorytm quicksort sortuj¹cy tablicê
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - tablica dynamiczna do posortowania
 * @param a - zmienna przechowaj¹ca indeks pierwszego elementu tablicy któr¹ sortujemy
 * @param b - zmienna przechowaj¹ca indeks ostatniego elementu tablicy któr¹ sortujemy
*/
template <typename E>
void QuickSortStep(E* S, int a, int b);

/**
 * max->min
 * @brief funkcja pomocnicza wywo³uj¹ca algorytm quicksort sortuj¹cy tablicê lub czêœæ tablicy w kolejnosci malej¹cej
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - tablica dynamiczna do posortowania
 * @param proc - iloœæ pocz¹tkowych elementów, wyra¿ona w %, która ma zostaæ posortowana
*/
template <typename E> // quick-sort S
void _backQuickSort(E* S, int size, double proc);

/**
 * @brief funkcja pomocnicza realizuj¹ca algorytm quicksort sortuj¹cy teblicê
 * @tparam E - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param S - tablica dynamiczna do posortowania
 * @param a - zmienna przechowaj¹ca indeks pierwszego elementu tablicy który sortujemy
 * @param b - zmienna przechowaj¹ca indeks ostatniego elementu tablicy który sortujemy
*/
template <typename E>
void _backQuickSortStep(E* S, int a, int b);


/*rozwiniêcia nag³ówków funkcji*/


template <typename E> // quick-sort S
void QuickSort(std::vector<E>& S, double proc) {
	if (S.size() <= 1) return; // jeœli jest tylko jeden element, zakoñcz sortowanie
	QuickSortStep(S, 0, (S.size() - 1)*(proc/100)); // wywo³anie sortowania
}

template <typename E>
void QuickSortStep(std::vector<E>& S, int a, int b) {
	if (a >= b) return; // jeœli zorta³ jeden lub 0 elementów, zakoñcz sortowanie
	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
	int l = a; // wybranie pierwszego elementu wektora jako indeksu do iteracji
	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
	while (l <= r) {
		while (l <= r && ( S[l] <= pivot)) l++; // skanowanie wektora od pocz¹tku, dopóki nie zostanie napotkana wiêksza wartoœæ 
												// jeœli mamy > to sortuje malej¹co, jeœli <  to rosn¹co
		while (r >= l && (S[r] >= pivot)) r--;  // skanowanie wektora od koñca, dopóki nie zostanie napotkana mniejsza wartoœæ
											    // jeœli mamy < to sortuje malej¹co, jeœli >  to rosn¹co
		if (l < r) // oba elementy znalezione
			std::swap(S[l], S[r]);
	} // pêtla wykonuje siê, dopóki indeksy l i r nie zamieni¹ siê stronami wzglêdem œrodka wektora
	std::swap(S[l], S[b]); // przechowaj piwot w elemncie o indeksie l
	QuickSortStep(S, a, l - 1); // rekurencja od pocz¹tku wektora
	QuickSortStep(S, l + 1, b); // rekurencja od koñca wektora
}

template <typename E> // quick-sort S
void _backQuickSort(std::vector<E>& S, double proc) {
	if (S.size() <= 1) return; // jeœli jest tylko jeden element, zakoñcz sortowanie
	_backQuickSortStep(S, 0, (S.size() - 1) * (proc / 100)); // call sort utility
}


template <typename E>
void _backQuickSortStep(std::vector<E>& S, int a, int b) {
	if (a >= b) return; // jeœli zorta³ jeden lub 0 elementów, zakoñcz sortowanie
	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
	int l = a; // wybranie pierwszego elementu wektora jako indeksu do iteracji
	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
	while (l <= r) {
		while (l <= r && (S[l] >= pivot)) l++; // skanowanie wektora od pocz¹tku, dopóki nie zostanie napotkana wiêksza wartoœæ 
											   // jeœli mamy > to sortuje malej¹co, jeœli <  to rosn¹co
		while (r >= l && (S[r] <= pivot)) r--; // skanowanie wektora od koñca, dopóki nie zostanie napotkana mniejsza wartoœæ
										       // jeœli mamy < to sortuje malej¹co, jeœli >  to rosn¹co
		if (l < r) // oba elementy znalezione
			std::swap(S[l], S[r]);
	} // pêtla wykonuje siê, dopóki indeksy l i r nie zamieni¹ siê stronami wzglêdem œrodka wektora
	std::swap(S[l], S[b]); // przechowaj piwot w elemncie o indeksie l
	_backQuickSortStep(S, a, l - 1); // rekurencja od pocz¹tku wektora
	_backQuickSortStep(S, l + 1, b); // rekurencja od koñca wektora
}


template <typename E> // quick-sort S
void QuickSort(E* S, int size, double proc) {
	if (size <= 1) return; // jeœli jest tylko jeden element, zakoñcz sortowanie
	QuickSortStep(S, 0, (int) ((size-1) * (proc / 100) ) ); // wywo³anie sortowania
}


template <typename E>
void QuickSortStep(E* S, int a, int b) {
	if (a >= b) return; // jeœli zorta³ jeden lub 0 elementów, zakoñcz sortowanie
	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
	int l = a; // wybranie pierwszego elementu tablicy jako indeksu do iteracji
	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
	while (l <= r) {
		while (l <= r && (S[l] <= pivot)) l++; // skanowanie tablicy od pocz¹tku, dopóki nie zostanie napotkana wiêksza wartoœæ 
											   // jeœli mamy > to sortuje malej¹co, jeœli <  to rosn¹co
		while (r >= l && (S[r] >= pivot)) r--; // skanowanie tablicy od koñca, dopóki nie zostanie napotkana mniejsza wartoœæ
											   // jeœli mamy < to sortuje malej¹co, jeœli >  to rosn¹co
		if (l < r) // oba elementy znalezione
			Exchange(S,l,r);
	} // pêtla wykonuje siê, dopóki indeksy l i r nie zamieni¹ siê stronami wzglêdem œrodka wektora
	Exchange(S,l,b); // przechowaj piwot w elemncie o indeksie l
	QuickSortStep(S, a, l - 1); // rekurencja od pocz¹tku tablicy
	QuickSortStep(S, l + 1, b); // rekurencja od koñca tablicy
}



template <typename E> // quick-sort S
void _backQuickSort(E* S, int size, double proc) {
	if (size <= 1) return; // jeœli jest tylko jeden element, zakoñcz sortowanie
	_backQuickSortStep(S, 0, (size-1) * (proc / 100)); // wywo³anie sortowania
}


template <typename E>
void _backQuickSortStep(E* S, int a, int b) {
	if (a >= b) return; // jeœli zorta³ jeden lub 0 elementów, zakoñcz sortowanie
	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
	int l = a; // wybranie pierwszego elementu wektora jako indeksu do iteracji
	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
	while (l <= r) {
		while (l <= r && (S[l] >= pivot)) l++; // skanowanie wektora od pocz¹tku, dopóki nie zostanie napotkana wiêksza wartoœæ,
											   // jeœli mamy > to sortuje malej¹co, jeœli <  to rosn¹co
		while (r >= l && (S[r] <= pivot)) r--; // skanowanie wektora od koñca, dopóki nie zostanie napotkana mniejsza wartoœæ
											   // jeœli mamy < to sortuje malej¹co, jeœli >  to rosn¹co
		if (l < r) // oba elementy znalezione
			Exchange(S,l,r);
	} // pêtla wykonuje siê, dopóki indeksy l i r nie zamieni¹ siê stronami wzglêdem œrodka wektora
	Exchange(S,l,b); // przechowaj piwot w elemncie o indeksie l
	_backQuickSortStep(S, a, l - 1); // rekurencja od pocz¹tku wektora
	_backQuickSortStep(S, l + 1, b); // rekurencja od koñca wektora
}