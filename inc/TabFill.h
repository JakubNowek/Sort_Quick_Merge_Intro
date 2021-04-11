#pragma once

#include <iostream>
#include <vector>
#include "Rozmiar.h"
#include <cstdlib>
#include <time.h>

/*nag³ówki*/

/**
 * @brief funkcja wype³niaj¹ca tablicê wektorów
 * @tparam SType - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param toFill - tablica wektorów któr¹ chcemy wype³niæ
 * @param Size - rozmiar wektorów
*/
template< typename SType>
void  TabFill(std::vector<SType> toFill[], int Size);

/**
 * @brief przeci¹¿enie TabFill dla tablicy dynamicznej dwuwymiarowej, funkcja wype³niaj¹ca tablicê
 * @tparam SType - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna dwuwymiarowa któr¹ chcemy wype³niæ
 * @param Size - iloœc kolumn tablicy
*/
template <typename SType>
void TabFill(SType** Array, int Size);


/*rozwiniêcia nag³ówków funkcji*/

template< typename SType>
void  TabFill(std::vector<SType> toFill[], int Size) {
	std::cout << "Wylosowano " << ROZMIAR << " tablic " << Size <<" elementowych."<< std::endl;
	srand(time(NULL)); /*Funkcja inicjalizuj¹ca funkcjê rand(), przy ka¿dym uruchomieniu programu uzyskujemy inn¹ sekwencjê liczb losowych*/
	
	/*czyszczenie wektora*/
	for (int i = 0; i < ROZMIAR; i++) { /*przechodzimy przez kolejne wektory (od wektora 0 do wektora ROZMIAR)*/
		for (int j = 0; j < Size; j++) { /*przechodzimy przez kolejne elementy wektora (od 0 do Size)*/

			toFill[i].clear();
		}
	}
	/*wypelnianie wektora*/
	for (int i = 0; i < ROZMIAR; i++) { /*przechodzimy przez kolejne wektory (od wektora 0 do wektora ROZMIAR)*/
		for (int j = 0; j < Size; j++) { /*przechodzimy przez kolejne elementy wektora (od 0 do Size)*/

			toFill[i].push_back((rand() % RANGE)/DECIMAL); /*dodawanie do kolejnych pol wektora liczb losowych calkowitych z zakresu od 1 - 10*/
		}
	}
}


template <typename SType>
void TabFill(SType** Array, int Size) {
	std::cout << "Wylosowano " << ROZMIAR << " tablic " << Size << " elementowych." << std::endl;
	srand((SType)time(NULL));			/*Funkcja inicjalizuj¹ca funkcjê rand(), przy ka¿dym uruchomieniu programu uzyskujemy inn¹ sekwencjê liczb losowych*/
	for (int i = 0; i < ROZMIAR; i++)
	{
		Array[i] = new SType[Size];
			for (int j = 0; j < Size; j++)
			{
				Array[i][j] = ((rand() % RANGE) / DECIMAL);
			}
	}
	
}

