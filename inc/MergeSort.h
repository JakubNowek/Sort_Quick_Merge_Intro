#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include "Rozmiar.h"
#include "Exchange.h"


/*nag��wki*/


/*funkcje dla wektor�w*/
/**
 * @brief - funkcja realizuj�ca algorytm sortowania przez scalanie na wektorach 
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor
*/
template <typename E> // merge-sort S
void MergeSort(std::vector<E>& S);

/**
 * @brief funkcja odpowiedzialna za ��czenie podzbior�w
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param in - pocz�tkowy wektor wej�ciowy
 * @param out - pocz�tkowy wektor wyj�ciowy
 * @param b - zmienna przechowuj�ca pocz�tek pierwszego podzbioru
 * @param m - zmienna przechowuj�ca pocz�tek drugiego podzbioru
*/
template <typename E>
void Merge(std::vector<E>& in, std::vector<E>& out, int b, int m);

/* funkcje dla tablic  */
/**
 * @brief przeci��enie funkcji MergeSort dla tablic, funkcja realizuj�ca algorytm sortowania przez scalanie
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowuj�ca indeks pierwszego elementu tablicy dynamicznej
 * @param r - zmienna przechowuj�ca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E> // quick-sort S
void MergeSort(E* tab, int l, int r);

/**
 * @brief funkcja odpowiedzialna za ��czenie podzbior�w
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowuj�ca indeks pierwszego elementu tablicy dynamicznej
 * @param m - rozmiar podzbioru
 * @param r - zmienna przechowuj�ca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E>
void Merge(E* tab, int l, int m, int r);

/*sortowania pomocnicze MAX -> MIN*/


/*funkcje dla wektor�w*/
/**
 * @brief - funkcja pomocnicza realizuj�ca algorytm sortowania niemalej�co przez scalanie na wektorach 
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param S - wektor
*/
template <typename E> // merge-sort S
void _backMergeSort(std::vector<E>& S);

/**
 * @brief funkcja pomocnicza odpowiedzialna za ��czenie podzbior�w
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param in - pocz�tkowy wektor wej�ciowy
 * @param out - pocz�tkowy wektor wyj�ciowy
 * @param b - zmienna przechowuj�ca pocz�tek pierwszego podzbioru
 * @param m - zmienna przechowuj�ca pocz�tek drugiego podzbioru
*/
template <typename E>
void _backMerge(std::vector<E>& in, std::vector<E>& out, int b, int m);

/* funkcje dla tablic  */
/**
 * @brief przeci��enie funkcji MergeSort dla tablic, funkcja realizuj�ca algorytm sortowania niemalej�co przez scalanie
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowuj�ca indeks pierwszego elementu tablicy dynamicznej
 * @param r - zmienna przechowuj�ca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E> // quick-sort S
void _backMergeSort(E* tab, int l, int r);

/**
 * @brief funkcja pomocnicza odpowiedzialna za ��czenie podzbior�w
 * @tparam E - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param tab - tablica dynamiczna
 * @param l - zmienna przechowuj�ca indeks pierwszego elementu tablicy dynamicznej
 * @param m - rozmiar podzbioru
 * @param r - zmienna przechowuj�ca indeks ostatniego elementu tablicy dynamicznej (rozmiar - 1)
*/
template <typename E>
void _backMerge(E* tab, int l, int m, int r);




/*rozwini�cia nag��wk�w funkcji*/

template <typename E> // merge-sort S
void MergeSort(std::vector<E>& S) {
	typedef std::vector<E> vect;
	int n = S.size();

	// Wektory pomocnicze
	vect v1(S); vect* in = &v1; // pocz�tkowy wektor wej�ciowy
	vect v2(n); vect* out = &v2; // poczatkowy wektor wyj�ciowy
	for (int m = 1; m < n; m *= 2) { // podwajanie rozmiaru podzbior�w
		for (int b = 0; b < n; b += 2 * m) { // pocz�tek podzbioru 
			Merge(*in, *out, b, m); // scalanie podzbior�w
		}
		std::swap(in, out); // zamiana wektora wej�ciowego z wyj�ciowym
	}
	S = *in; // przepisanie posortowanego wektora do wektora podanego do funkcji
}


template <typename E>
void Merge(std::vector<E>& in, std::vector<E>& out, int b, int m) {
	int i = b; // pocz�tek pierwszego podzbioru
	int j = b + m; // pocz�tek drugiego podzbioru
	int n = in.size();
	int e1 = std::min(b + m, n); // koniec pierwszego podzbiory
	int e2 = std::min(b + 2 * m, n); // koniec drugiego podzbioru
	int k = b;
	while ((i < e1) && (j < e2)) {
		if (!(in[j] <= in[i])) // przy��cz mniejszy do S   < oznacza sortowanie rosn�ce, > sortowanie malej�ce
		{
			out[k++] = in[i++];
		}
		else
		{
			out[k++] = in[j++];
		}
	}
	while (i < e1) { // je�li w podzbiorze pierwszym pozosta�y jakie� elementy, kopiujemy je do S
		out[k++] = in[i++];
	}
	while (j < e2) { // je�li w podzbiorze drugim pozosta�y jakie� elementy, kopiujemy je do S
		out[k++] = in[j++];
	}
}

template <typename E> // quick-sort S
void MergeSort(E* tab, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		MergeSort(tab, l, m);
		MergeSort(tab, m + 1, r);
		Merge(tab, l, m, r); //scalanie podzbior�w
	}
}

template <typename E>
void Merge(E* tab, int l, int m, int r) {
	int lSize = m - l + 1;
	int rSize = r - m;

	//Tablice pomocnicze
	E* tabL = new int[lSize];
	E* tabR = new int[rSize];

	for (int x = 0; x < lSize; x++)	 // Kopiowanie danych do podzbior�w (tablic) pomocniczych
		tabL[x] = tab[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];

	int indexL = 0;
	int indexR = 0;
	int currIndex;

	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++) 	//��czenie podzbior�w R i L
	{
		if (tabL[indexL] <= tabR[indexR]) // <=  niemalej�co, >== nierosn�co
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}

	while (indexL < lSize) // je�li w podzbiorze pierwszym pozosta�y jakie� elementy, kopiujemy je do S
		tab[currIndex++] = tabL[indexL++];

	while (indexR < rSize) // je�li w podzbiorze drugim pozosta�y jakie� elementy, kopiujemy je do S
		tab[currIndex++] = tabR[indexR++];

	delete[] tabL; //usuwanie podzbior�w (tablic dynamicznych) pomocniczych
	delete[] tabR;
}


/* ROZWINIECIE POMOCNICZYCH */


template <typename E> // merge-sort S
void _backMergeSort(std::vector<E>& S) {
	typedef std::vector<E> vect;
	int n = S.size();

	// Wektory pomocnicze
	vect v1(S); vect* in = &v1; // pocz�tkowy wektor wej�ciowy
	vect v2(n); vect* out = &v2; // poczatkowy wektor wyj�ciowy
	for (int m = 1; m < n; m *= 2) { // podwajanie rozmiaru podzbior�w
		for (int b = 0; b < n; b += 2 * m) { // pocz�tek podzbioru 
			_backMerge(*in, *out, b, m); // scalanie podzbior�w
		}
		std::swap(in, out); // zamiana wektora wej�ciowego z wyj�ciowym
	}
	S = *in; // przepisanie posortowanego wektora do wektora podanego do funkcji
}


template <typename E>
void _backMerge(std::vector<E>& in, std::vector<E>& out, int b, int m) {
	int i = b; // pocz�tek pierwszego podzbioru
	int j = b + m; // pocz�tek drugiego podzbioru
	int n = in.size();
	int e1 = std::min(b + m, n); // koniec pierwszego podzbiory
	int e2 = std::min(b + 2 * m, n); // koniec drugiego podzbioru
	int k = b;
	while ((i < e1) && (j < e2)) {
		if (!(in[j] >= in[i])) // przy��cz mniejszy do S   < oznacza sortowanie rosn�ce, > sortowanie malej�ce
		{
			out[k++] = in[i++];
		}
		else
		{
			out[k++] = in[j++];
		}
	}
	while (i < e1) { // je�li w podzbiorze pierwszym pozosta�y jakie� elementy, kopiujemy je do S
		out[k++] = in[i++];
	}
	while (j < e2) { // je�li w podzbiorze drugim pozosta�y jakie� elementy, kopiujemy je do S
		out[k++] = in[j++];
	}
}

template <typename E> // quick-sort S
void _backMergeSort(E* tab, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		_backMergeSort(tab, l, m);
		_backMergeSort(tab, m + 1, r);
		_backMerge(tab, l, m, r); //scalanie podzbior�w
	}
}

template <typename E>
void _backMerge(E* tab, int l, int m, int r) {
	int lSize = m - l + 1;
	int rSize = r - m;

	//Tablice pomocnicze
	E* tabL = new int[lSize];
	E* tabR = new int[rSize];

	for (int x = 0; x < lSize; x++)	 // Kopiowanie danych do podzbior�w (tablic) pomocniczych
		tabL[x] = tab[l + x];
	for (int y = 0; y < rSize; y++)
		tabR[y] = tab[m + 1 + y];

	int indexL = 0;
	int indexR = 0;
	int currIndex;

	for (currIndex = l; indexL < lSize && indexR < rSize; currIndex++) 	//��czenie podzbior�w R i L
	{
		if (tabL[indexL] >= tabR[indexR]) // <=  niemalej�co, >== nierosn�co
			tab[currIndex] = tabL[indexL++];
		else
			tab[currIndex] = tabR[indexR++];
	}

	while (indexL < lSize) // je�li w podzbiorze pierwszym pozosta�y jakie� elementy, kopiujemy je do S
		tab[currIndex++] = tabL[indexL++];

	while (indexR < rSize) // je�li w podzbiorze drugim pozosta�y jakie� elementy, kopiujemy je do S
		tab[currIndex++] = tabR[indexR++];

	delete[] tabL; //usuwanie podzbior�w (tablic dynamicznych) pomocniczych
	delete[] tabR;

}
