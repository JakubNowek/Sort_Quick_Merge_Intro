#pragma once
#include <iostream>
#include <vector>
#include "Rozmiar.h"

/*Nag��wki*/

/**
 * @brief funkcja odpowiada za wypisywanie element�w tablicy wektor�w
 * @tparam Type  - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param toDisplay - tablica wektor�w
*/
template <typename Type>
void Display(std::vector<Type> toDisplay[]);

/**
 * @brief przeci��enie funkcji Display, odpowiada za wypisywanie element�w dwuwymiarowej tablicy dynamicznej
 * @tparam Type  - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param toDisplay - dynamiczna tablica dwuwymiarowa
 * @param size - zmienna przechowuj�ca ilo�c kolumn tablicy
*/
template <typename Type>
void Display(Type** Array, int size);


/*rozwini�cia nag��wk�w*/

template <typename Type>
void Display(std::vector<Type> toDisplay[] ) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < toDisplay[i].size(); j++) {
			std::cout.width(6); //ustalanie szeroko�ci na jakiej ma by� wy�wietlona liczba
			std::cout<<left<<toDisplay[i][j]<<" ";  // left - justowanie wy�wietlanych liczb do lewej
		}
		cout << endl;
	}
}

template <typename Type>
void Display(Type** Array, int size) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < size; j++) {
			std::cout.width(6); //ustalanie szeroko�ci na jakiej ma by� wy�wietlona liczba
			std::cout << left << Array[i][j] << " ";  // left - justowanie wy�wietlanych liczb do lewej
		}
		std::cout << endl;
	}
}