#pragma once
#include <iostream>
#include <vector>
#include "Rozmiar.h"
using namespace std;

template <typename Type>
void Display(vector<Type> toDisplay[] ) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < toDisplay[i].size(); j++) {
			printf("%5d ", toDisplay[i][j]);				//dziala tylko dla int
			//cout<< toDisplay[i][j]<<" ";  //dziala dla wszystkich ale brzydko wyglada
		}
		cout << endl;
	}
}