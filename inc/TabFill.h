#pragma once

#include <iostream>
#include <vector>
#include "Rozmiar.h"
#include <cstdlib>
#include <time.h>
using namespace std;

//void  TabFill(vector<int> toFill[], int Size);
template< typename SType>
void  TabFill(vector<SType> toFill[], int Size) {
	std::cout << "Wylosowana tablica: " << ROZMIAR << " x " << Size << std::endl;
	srand(time(NULL)); /*Funkcja inicjalizuj¹ca funkcjê rand(), przy ka¿dym uruchomieniu programu uzyskujemy inn¹ sekwencjê liczb losowych*/

	for (int i = 0; i < ROZMIAR; i++) { /*przechodzimy przez kolejne wektory (od wektora 0 do wektora ROZMIAR)*/
		for (int j = 0; j < Size; j++) { /*przechodzimy przez kolejne elementy wektora (od 0 do Size)*/

			toFill[i].push_back((rand() % RANGE)/DECIMAL); /*dodawanie do kolejnych pol wektora liczb losowych calkowitych z zakresu od 1 - 10*/
		}
	}
}

//przeci¹¿enie funkcji TabFill dla tablicy
template <typename SType>
void TabFill(SType** Array, int Size){
	srand((SType)time(NULL));					/*Funkcja inicjalizuj¹ca funkcjê rand(), przy ka¿dym uruchomieniu programu uzyskujemy inn¹ sekwencjê liczb losowych*/
	for (int i = 0; i < ROZMIAR; i++)
	{
		Array[i] = new SType[Size];
			for (int j = 0; j < Size; j++)
			{
				Array[i][j] = ((rand() % RANGE) / DECIMAL);
			}
	}

}