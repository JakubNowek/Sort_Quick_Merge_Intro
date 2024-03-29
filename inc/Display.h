#pragma once
#include <iostream>
#include <vector>
#include "Rozmiar.h"

/*Nagłówki*/

/**
 * @brief funkcja odpowiada za wypisywanie elementów tablicy wektorów
 * @tparam Type  - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param toDisplay - tablica wektorów
*/
template <typename Type>
void Display(std::vector<Type> toDisplay[]);

/**
 * @brief przeciążenie funkcji Display, odpowiada za wypisywanie elementów dwuwymiarowej tablicy dynamicznej
 * @tparam Type  - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param toDisplay - dynamiczna tablica dwuwymiarowa
 * @param size - zmienna przechowująca ilośc kolumn tablicy
*/
template <typename Type>
void Display(Type** Array, int size);


/*rozwinięcia nagłówków*/

template <typename Type>
void Display(std::vector<Type> toDisplay[] ) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < toDisplay[i].size(); j++) {
			std::cout.width(6); //ustalanie szerokości na jakiej ma być wyświetlona liczba
			std::cout<<left<<toDisplay[i][j]<<" ";  // left - justowanie wyświetlanych liczb do lewej
		}
		cout << endl;
	}
}

template <typename Type>
void Display(Type** Array, int size) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < size; j++) {
			std::cout.width(6); //ustalanie szerokości na jakiej ma być wyświetlona liczba
			std::cout << left << Array[i][j] << " ";  // left - justowanie wyświetlanych liczb do lewej
		}
		std::cout << endl;
	}
}