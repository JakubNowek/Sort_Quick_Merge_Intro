#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"
#include "Exchange.h"

/*nag��wki*/

/* Wektory */
/** 
 * min->max
 * @brief funkcja wywo�uj�ca algorytm quicksort sortuj�cy wektor lub cz�� wektora
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param proc - ilo�� pocz�tkowych element�w, wyra�ona w %, kt�ra ma zosta posortowana
*/
template <typename E> // quick-sort S
void QuickSort(std::vector<E>& S, double proc);

/**
 * @brief funkcja realizuj�ca algorytm quicksort sortuj�cy wektor
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param a - zmienna przechowaj�ca indeks pierwszego elementu wektora kt�ry sortujemy
 * @param b - zmienna przechowaj�ca indeks ostatniego elementu wektora kt�ry sortujemy
*/
template <typename E>
void QuickSortStep(std::vector<E>& S, int a, int b);

/**
 * max->min
 * @brief funkcja pomocnicza wywo�uj�ca algorytm quicksort sortuj�cy wektor lub cz�� wektora w kolejnosci malej�cej
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param proc - ilo�� pocz�tkowych element�w, wyra�ona w %, kt�ra ma zosta posortowana
*/
template <typename E> // quick-sort S
void _backQuickSort(std::vector<E>& S, double proc);

/**
 * @brief funkcja pomocnicza realizuj�ca algorytm quicksort sortuj�cy wektor
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor do posortowania
 * @param a - zmienna przechowaj�ca indeks pierwszego elementu wektora kt�ry sortujemy
 * @param b - zmienna przechowaj�ca indeks ostatniego elementu wektora kt�ry sortujemy
*/
template <typename E>
void _backQuickSortStep(std::vector<E>& S, int a, int b);

/* Tablice */
/**
 * algorytm zosta� wzi�ty ze strony http://algorytmy.ency.pl/artykul/quicksort i przet�umaczony na j�zyk angielski dla jednolito�ci
 * @brief funkcja realizuj�ca algorytm quicksort sortuj�cy tablic�
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - tablica dynamiczna do posortowania
 * @param pivot - zmienna przechowuj�ca indeks pierwszego elementu tablicy dynamicznej, przyj�ta jako klucz sortowania
 * @param n - zmienna przechowuj�ca rozmiar tablicy dynamicznej
*/
template <typename E>
void QuickSort(E* S, int pivot, int n);


///**
// * @brief funkcja wywo�uj�ca algorytm quicksort sortuj�cy tablic� lub cz�� tablicy
// * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
// * @param S - tablica do posortowania
// * @param size - zmienna przechowuj�ca rozmiar tablicy do sortowania
// * @param proc - ilo�� pocz�tkowych element�w, wyra�ona w %, kt�ra ma zosta posortowana
//*/
//template <typename E> // quick-sort S
//void QuickSort(E* S, int size, double proc);
//
///**
// * @brief funkcja realizuj�ca algorytm quicksort sortuj�cy tablic�
// * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
// * @param S - tablica dynamiczna do posortowania
// * @param a - zmienna przechowaj�ca indeks pierwszego elementu tablicy kt�r� sortujemy
// * @param b - zmienna przechowaj�ca indeks ostatniego elementu tablicy kt�r� sortujemy
//*/
//template <typename E>
//void QuickSortStep(E* S, int a, int b);
//
///**
// * max->min
// * @brief funkcja pomocnicza wywo�uj�ca algorytm quicksort sortuj�cy tablic� lub cz�� tablicy w kolejnosci malej�cej
// * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
// * @param S - tablica dynamiczna do posortowania
// * @param proc - ilo�� pocz�tkowych element�w, wyra�ona w %, kt�ra ma zosta� posortowana
//*/
//template <typename E> // quick-sort S
//void _backQuickSort(E* S, int size, double proc);
//
///**
// * @brief funkcja pomocnicza realizuj�ca algorytm quicksort sortuj�cy teblic�
// * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
// * @param S - tablica dynamiczna do posortowania
// * @param a - zmienna przechowaj�ca indeks pierwszego elementu tablicy kt�ry sortujemy
// * @param b - zmienna przechowaj�ca indeks ostatniego elementu tablicy kt�ry sortujemy
//*/
//template <typename E>
//void _backQuickSortStep(E* S, int a, int b);

/*rozwini�cia nag��wk�w funkcji*/


template <typename E> // quick-sort S
void QuickSort(std::vector<E>& S, double proc) {
	if (S.size() <= 1) return; // je�li jest tylko jeden element, zako�cz sortowanie
	QuickSortStep(S, 0, (S.size() - 1)*(proc/100)); // wywo�anie sortowania
}

template <typename E>
void QuickSortStep(std::vector<E>& S, int a, int b) {
	if (a >= b) return; // je�li zorta� jeden lub 0 element�w, zako�cz sortowanie
	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
	int l = a; // wybranie pierwszego elementu wektora jako indeksu do iteracji
	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
	while (l <= r) {
		while (l <= r && ( S[l] <= pivot)) l++; // skanowanie wektora od pocz�tku, dop�ki nie zostanie napotkana wi�ksza warto�� 
												// je�li mamy > to sortuje malej�co, je�li <  to rosn�co
		while (r >= l && (S[r] >= pivot)) r--;  // skanowanie wektora od ko�ca, dop�ki nie zostanie napotkana mniejsza warto��
											    // je�li mamy < to sortuje malej�co, je�li >  to rosn�co
		if (l < r) // oba elementy znalezione
			std::swap(S[l], S[r]);
	} // p�tla wykonuje si�, dop�ki indeksy l i r nie zamieni� si� stronami wzgl�dem �rodka wektora
	std::swap(S[l], S[b]); // przechowaj piwot w elemncie o indeksie l
	QuickSortStep(S, a, l - 1); // rekurencja od pocz�tku wektora
	QuickSortStep(S, l + 1, b); // rekurencja od ko�ca wektora
}

template <typename E> // quick-sort S
void _backQuickSort(std::vector<E>& S, double proc) {
	if (S.size() <= 1) return; // je�li jest tylko jeden element, zako�cz sortowanie
	_backQuickSortStep(S, 0, (S.size() - 1) * (proc / 100)); // call sort utility
}


template <typename E>
void _backQuickSortStep(std::vector<E>& S, int a, int b) {
	if (a >= b) return; // je�li zorta� jeden lub 0 element�w, zako�cz sortowanie
	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
	int l = a; // wybranie pierwszego elementu wektora jako indeksu do iteracji
	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
	while (l <= r) {
		while (l <= r && (S[l] >= pivot)) l++; // skanowanie wektora od pocz�tku, dop�ki nie zostanie napotkana wi�ksza warto�� 
											   // je�li mamy > to sortuje malej�co, je�li <  to rosn�co
		while (r >= l && (S[r] <= pivot)) r--; // skanowanie wektora od ko�ca, dop�ki nie zostanie napotkana mniejsza warto��
										       // je�li mamy < to sortuje malej�co, je�li >  to rosn�co
		if (l < r) // oba elementy znalezione
			std::swap(S[l], S[r]);
	} // p�tla wykonuje si�, dop�ki indeksy l i r nie zamieni� si� stronami wzgl�dem �rodka wektora
	std::swap(S[l], S[b]); // przechowaj piwot w elemncie o indeksie l
	_backQuickSortStep(S, a, l - 1); // rekurencja od pocz�tku wektora
	_backQuickSortStep(S, l + 1, b); // rekurencja od ko�ca wektora
}


//template <typename E> // quick-sort S
//void QuickSort(E* S, int size, double proc) {
//	if (size <= 1) return; // je�li jest tylko jeden element, zako�cz sortowanie
//	QuickSortStep(S, 0, (int) ((size-1) * (proc / 100) ) ); // wywo�anie sortowania
//}
//
//
//template <typename E>
//void QuickSortStep(E* S, int a, int b) {
//	if (a >= b) return; // je�li zorta� jeden lub 0 element�w, zako�cz sortowanie
//	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
//	int l = a; // wybranie pierwszego elementu tablicy jako indeksu do iteracji
//	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
//	while (l <= r) {
//		while (l <= r && (S[l] <= pivot)) l++; // skanowanie tablicy od pocz�tku, dop�ki nie zostanie napotkana wi�ksza warto�� 
//											   // je�li mamy > to sortuje malej�co, je�li <  to rosn�co
//		while (r >= l && (S[r] >= pivot)) r--; // skanowanie tablicy od ko�ca, dop�ki nie zostanie napotkana mniejsza warto��
//											   // je�li mamy < to sortuje malej�co, je�li >  to rosn�co
//		if (l < r) // oba elementy znalezione
//			Exchange(S,l,r);
//	} // p�tla wykonuje si�, dop�ki indeksy l i r nie zamieni� si� stronami wzgl�dem �rodka wektora
//	Exchange(S,l,b); // przechowaj piwot w elemncie o indeksie l
//	QuickSortStep(S, a, l - 1); // rekurencja od pocz�tku tablicy
//	QuickSortStep(S, l + 1, b); // rekurencja od ko�ca tablicy
//}
//
//
//
//template <typename E> // quick-sort S
//void _backQuickSort(E* S, int size, double proc) {
//	if (size <= 1) return; // je�li jest tylko jeden element, zako�cz sortowanie
//	_backQuickSortStep(S, 0, (size-1) * (proc / 100)); // wywo�anie sortowania
//}
//
//
//template <typename E>
//void _backQuickSortStep(E* S, int a, int b) {
//	if (a >= b) return; // je�li zorta� jeden lub 0 element�w, zako�cz sortowanie
//	E pivot = S[b]; // wybranie ostatniego elementu jako pivot
//	int l = a; // wybranie pierwszego elementu wektora jako indeksu do iteracji
//	int r = b - 1; // wybranie przedostatniego elementu wektora jako indesu do iteracji
//	while (l <= r) {
//		while (l <= r && (S[l] >= pivot)) l++; // skanowanie wektora od pocz�tku, dop�ki nie zostanie napotkana wi�ksza warto��,
//											   // je�li mamy > to sortuje malej�co, je�li <  to rosn�co
//		while (r >= l && (S[r] <= pivot)) r--; // skanowanie wektora od ko�ca, dop�ki nie zostanie napotkana mniejsza warto��
//											   // je�li mamy < to sortuje malej�co, je�li >  to rosn�co
//		if (l < r) // oba elementy znalezione
//			Exchange(S,l,r);
//	} // p�tla wykonuje si�, dop�ki indeksy l i r nie zamieni� si� stronami wzgl�dem �rodka wektora
//	Exchange(S,l,b); // przechowaj piwot w elemncie o indeksie l
//	_backQuickSortStep(S, a, l - 1); // rekurencja od pocz�tku wektora
//	_backQuickSortStep(S, l + 1, b); // rekurencja od ko�ca wektora
//}


template <typename E>
void QuickSort(E* S, int pivot, int n) {
    if (n > 1){
        int smaller_count = 0;
        int larger_count = 0;

        E end = pivot + n;
        int t; // Zmienna tymczasowa

        // Przeniesienie elementow wokol klucza osiowego
        for (int i = (pivot + 1); i < end; ++i){

            if (S[i] < S[pivot]) {
                if (larger_count > 0) {
                    // Przeniesienie elementu mniejszego od klucza osiowego
                    // przed elementy wieksze od klucza osiowego
                    t = S[pivot + smaller_count + 1];
                    S[pivot + smaller_count + 1] = S[i];
                    S[i] = t;
                }
                ++smaller_count;
            }
            else {
                ++larger_count;
            }

        }
        // Wstawienie klucza osiowego na wlasciwe miejsce
        t = S[pivot + smaller_count];
        S[pivot + smaller_count] = S[pivot];
        S[pivot] = t;

        // Wywo�anie rekurencyjne
        QuickSort(S, pivot, smaller_count);
        QuickSort(S, end - larger_count, larger_count);

    }
}