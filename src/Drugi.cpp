#include "Drugi.h"
#include <cstdlib>
#include <time.h>

void  Drugi(vector<int> toFill[],int size) {
	std::cout << "Drugi" << std::endl;
	srand(time(NULL)); //Funkcja inicjalizuj�ca funkcj� rand(), przy ka�dym uruchomieniu programu uzyskujemy inn� sekwencj� liczb losowych

	for (int i = 0; i < ROZMIAR; i++ ) {
		for (int j = 0; j < size; j++) {

			toFill[i].push_back(rand()%10);
		}
	}
}