#include "TabFill.h"
#include <cstdlib>
#include <time.h>

void  TabFill(vector<int> toFill[],int size) {
	std::cout << "Wylosowana tablica: "<<ROZMIAR<<" x "<<size<< std::endl;
	srand(time(NULL)); //Funkcja inicjalizuj¹ca funkcjê rand(), przy ka¿dym uruchomieniu programu uzyskujemy inn¹ sekwencjê liczb losowych

	for (int i = 0; i < ROZMIAR; i++ ) { //przechodzimy przez kolejne wektory (od wektora 0 do wektora ROZMIAR)
		for (int j = 0; j < size; j++) { //przechodzimy przez kolejne elementy wektora (od 0 do size)

			toFill[i].push_back(rand()%10);
		}
	}
}