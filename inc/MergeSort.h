#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"
#include "Exchange.h"


/*nagłówki*/


/*funkcje dla wektorów*/
/**
 * @brief - funkcja realizująca algorytm sortowania przez scalanie na wektorach 
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param S - wektor
*/
template <typename E> // merge-sort S
void MergeSort(std::vector<E>& S);

/**
 * @brief funkcja odpowiedzialna za łączenie podzbiorów
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param in - początkowy wektor wejściowy
 * @param out - początkowy wektor wyjściowy
 * @param b - zmienna przechowująca początek pierwszego podzbioru
 * @param m - zmienna przechowująca początek drugiego podzbioru
*/
template <typename E>
void Merge(std::vector<E>& in, std::vector<E>& out, int b, int m);

/* funkcje dla tablic  */
/**
 * @brief przeciążenie funkcji MergeSort dla tablic, funkcja realizująca algorytm sortowania przez scalanie
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowująca indeks pierwszego elementu tablicy dynamicznej
 * @param r - zmienna przechowująca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E> // quick-sort S
void MergeSort(E* tab, int l, int r);

/**
 * @brief funkcja odpowiedzialna za łączenie podzbiorów
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowująca indeks pierwszego elementu tablicy dynamicznej
 * @param m - rozmiar podzbioru
 * @param r - zmienna przechowująca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E>
void Merge(E* tab, int l, int m, int r);

/*sortowania pomocnicze MAX -> MIN*/


/*funkcje dla wektorów*/
/**
 * @brief - funkcja pomocnicza realizująca algorytm sortowania niemalejąco przez scalanie na wektorach 
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param S - wektor
*/
template <typename E> // merge-sort S
void _backMergeSort(std::vector<E>& S);

/**
 * @brief funkcja pomocnicza odpowiedzialna za łączenie podzbiorów
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param in - początkowy wektor wejściowy
 * @param out - początkowy wektor wyjściowy
 * @param b - zmienna przechowująca początek pierwszego podzbioru
 * @param m - zmienna przechowująca początek drugiego podzbioru
*/
template <typename E>
void _backMerge(std::vector<E>& in, std::vector<E>& out, int b, int m);

/* funkcje dla tablic  */
/**
 * @brief przeciążenie funkcji MergeSort dla tablic, funkcja realizująca algorytm sortowania niemalejąco przez scalanie
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowująca indeks pierwszego elementu tablicy dynamicznej
 * @param r - zmienna przechowująca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E> // quick-sort S
void _backMergeSort(E* tab, int l, int r);

/**
 * @brief funkcja pomocnicza odpowiedzialna za łączenie podzbiorów
 * @tparam E - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowująca indeks pierwszego elementu tablicy dynamicznej
 * @param m - rozmiar podzbioru
 * @param r - zmienna przechowująca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E>
void _backMerge(E* tab, int l, int m, int r);




/*rozwinięcia nagłówków funkcji*/

template <typename E> // merge-sort S
void MergeSort(std::vector<E>& S) {
	typedef std::vector<E> vect;
	int n = S.size();

	// Wektory pomocnicze
	vect v1(S); vect* in = &v1; // początkowy wektor wejściowy
	vect v2(n); vect* out = &v2; // poczatkowy wektor wyjściowy
	for (int m = 1; m < n; m *= 2) { // podwajanie rozmiaru podzbiorów
		for (int b = 0; b < n; b += 2 * m) { // początek podzbioru 
			Merge(*in, *out, b, m); // scalanie podzbiorów
		}
		std::swap(in, out); // zamiana wektora wejściowego z wyjściowym
	}
	S = *in; // przepisanie posortowanego wektora do wektora podanego do funkcji
}


template <typename E>
void Merge(std::vector<E>& in, std::vector<E>& out, int b, int m) {
	int i = b; // początek pierwszego podzbioru
	int j = b + m; // początek drugiego podzbioru
	int n = in.size();
	int e1 = std::min(b + m, n); // koniec pierwszego podzbiory
	int e2 = std::min(b + 2 * m, n); // koniec drugiego podzbioru
	int k = b;
	while ((i < e1) && (j < e2)) {
		if (!(in[j] <= in[i])) // przyłącz mniejszy do S   < oznacza sortowanie rosnące, > sortowanie malejące
		{
			out[k++] = in[i++];
		}
		else
		{
			out[k++] = in[j++];
		}
	}
	while (i < e1) { // jeśli w podzbiorze pierwszym pozostały jakieś elementy, kopiujemy je do S
		out[k++] = in[i++];
	}
	while (j < e2) { // jeśli w podzbiorze drugim pozostały jakieś elementy, kopiujemy je do S
		out[k++] = in[j++];
	}
}

template <typename E> // quick-sort S
void MergeSort(E* tab, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		MergeSort(tab, l, m);
		MergeSort(tab, m + 1, r);
		Merge(tab, l, m, r); //scalanie podzbiorów
	}
}

template <typename E>
void Merge(E* tab, int l, int m, int r) {
	int lSize = m - l + 1;
	int rSize = r - m;

	//Tablice pomocnicze
	E* tabL = new int[lSize];
	E* tabR = new int[rSize];

	for (int x = 0; x < lSize; x++)	 // Kopiowanie danych do podzbiorów (tablic) pomocniczych
		tabL[x] = tab[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];

	int indexL = 0;
	int indexR = 0;
	int currIndex;

	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++) 	//Łączenie podzbiorów R i L
	{
		if (tabL[indexL] <= tabR[indexR]) // <=  niemalejąco, >== nierosnąco
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}

	while (indexL < lSize) // jeśli w podzbiorze pierwszym pozostały jakieś elementy, kopiujemy je do S
		tab[currIndex++] = tabL[indexL++];

	while (indexR < rSize) // jeśli w podzbiorze drugim pozostały jakieś elementy, kopiujemy je do S
		tab[currIndex++] = tabR[indexR++];

	delete[] tabL; //usuwanie podzbiorów (tablic dynamicznych) pomocniczych
	delete[] tabR;
}


/* ROZWINIECIE POMOCNICZYCH */


template <typename E> // merge-sort S
void _backMergeSort(std::vector<E>& S) {
	typedef std::vector<E> vect;
	int n = S.size();

	// Wektory pomocnicze
	vect v1(S); vect* in = &v1; // początkowy wektor wejściowy
	vect v2(n); vect* out = &v2; // poczatkowy wektor wyjściowy
	for (int m = 1; m < n; m *= 2) { // podwajanie rozmiaru podzbiorów
		for (int b = 0; b < n; b += 2 * m) { // początek podzbioru 
			_backMerge(*in, *out, b, m); // scalanie podzbiorów
		}
		std::swap(in, out); // zamiana wektora wejściowego z wyjściowym
	}
	S = *in; // przepisanie posortowanego wektora do wektora podanego do funkcji
}


template <typename E>
void _backMerge(std::vector<E>& in, std::vector<E>& out, int b, int m) {
	int i = b; // początek pierwszego podzbioru
	int j = b + m; // początek drugiego podzbioru
	int n = in.size();
	int e1 = std::min(b + m, n); // koniec pierwszego podzbiory
	int e2 = std::min(b + 2 * m, n); // koniec drugiego podzbioru
	int k = b;
	while ((i < e1) && (j < e2)) {
		if (!(in[j] >= in[i])) // przyłącz mniejszy do S   < oznacza sortowanie rosnące, > sortowanie malejące
		{
			out[k++] = in[i++];
		}
		else
		{
			out[k++] = in[j++];
		}
	}
	while (i < e1) { // jeśli w podzbiorze pierwszym pozostały jakieś elementy, kopiujemy je do S
		out[k++] = in[i++];
	}
	while (j < e2) { // jeśli w podzbiorze drugim pozostały jakieś elementy, kopiujemy je do S
		out[k++] = in[j++];
	}
}

template <typename E> // quick-sort S
void _backMergeSort(E* tab, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		_backMergeSort(tab, l, m);
		_backMergeSort(tab, m + 1, r);
		_backMerge(tab, l, m, r); //scalanie podzbiorów
	}
}

template <typename E>
void _backMerge(E* tab, int l, int m, int r) {
	int lSize = m - l + 1;
	int rSize = r - m;

	//Tablice pomocnicze
	E* tabL = new int[lSize];
	E* tabR = new int[rSize];

	for (int x = 0; x < lSize; x++)	 // Kopiowanie danych do podzbiorów (tablic) pomocniczych
		tabL[x] = tab[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];

	int indexL = 0;
	int indexR = 0;
	int currIndex;

	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++) 	//Łączenie podzbiorów R i L
	{
		if (tabL[indexL] >= tabR[indexR]) // <=  niemalejąco, >== nierosnąco
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}

	while (indexL < lSize) // jeśli w podzbiorze pierwszym pozostały jakieś elementy, kopiujemy je do S
		tab[currIndex++] = tabL[indexL++];

	while (indexR < rSize) // jeśli w podzbiorze drugim pozostały jakieś elementy, kopiujemy je do S
		tab[currIndex++] = tabR[indexR++];

	delete[] tabL; //usuwanie podzbiorów (tablic dynamicznych) pomocniczych
	delete[] tabR;

}
