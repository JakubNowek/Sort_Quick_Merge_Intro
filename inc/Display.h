#pragma once
#include <iostream>
#include <vector>
#include "Rozmiar.h"
using namespace std;

template <typename Type>
void Display(vector<Type> toDisplay[] ) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < toDisplay[i].size(); j++) {
			cout.width(6); //ustalanie szeroko�ci na jakiej ma by� wy�wietlona liczba
			cout<<left<<toDisplay[i][j]<<" ";  // left - justowanie wy�wietlanych liczb do lewej
		}
		cout << endl;
	}
}

template <typename Type>
void Display(Type** Array, int size) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < size; j++) {
			cout.width(6); //ustalanie szeroko�ci na jakiej ma by� wy�wietlona liczba
			cout << left << Array[i][j] << " ";  // left - justowanie wy�wietlanych liczb do lewej
		}
		cout << endl;
	}
}