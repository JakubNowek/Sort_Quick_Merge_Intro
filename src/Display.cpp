#include "Display.h"
#include <iostream>

void Display(vector<int> toDisplay[], int size) {

	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < toDisplay[i].size(); j++) {
			printf("%5i ", toDisplay[i][j]);
			//cout<< tab[i][j]<<" ";
		}
		cout << endl;
	}
}