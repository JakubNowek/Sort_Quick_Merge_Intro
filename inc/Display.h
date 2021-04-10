#pragma once
#include <iostream>
#include <vector>
#include "Rozmiar.h"

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