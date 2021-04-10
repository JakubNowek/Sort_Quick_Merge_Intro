#pragma once
#include <iostream>
#include <vector>
#include "Rozmiar.h"

/*Nag³ówki*/

/**
 * @brief funkcja odpowiada za wypisywanie elementów tablicy wektorów
 * @tparam Type  - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param toDisplay - tablica wektorów
*/
template <typename Type>
void Display(std::vector<Type> toDisplay[]);

/**
 * @brief przeci¹¿enie funkcji Display, odpowiada za wypisywanie elementów dwuwymiarowej tablicy dynamicznej
 * @tparam Type  - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param toDisplay - dynamiczna tablica dwuwymiarowa
 * @param size - zmienna przechowuj¹ca iloœc kolumn tablicy
*/
template <typename Type>
void Display(Type** Array, int size);


/*rozwiniêcia nag³ówków*/

template <typename Type>
void Display(std::vector<Type> toDisplay[] ) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < toDisplay[i].size(); j++) {
			std::cout.width(6); //ustalanie szerokoœci na jakiej ma byæ wyœwietlona liczba
			std::cout<<left<<toDisplay[i][j]<<" ";  // left - justowanie wyœwietlanych liczb do lewej
		}
		cout << endl;
	}
}

template <typename Type>
void Display(Type** Array, int size) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < size; j++) {
			std::cout.width(6); //ustalanie szerokoœci na jakiej ma byæ wyœwietlona liczba
			std::cout << left << Array[i][j] << " ";  // left - justowanie wyœwietlanych liczb do lewej
		}
		std::cout << endl;
	}
}