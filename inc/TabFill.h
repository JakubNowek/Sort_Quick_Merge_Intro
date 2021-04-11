#pragma once

#include <iostream>
#include <vector>
#include "Rozmiar.h"
#include <cstdlib>
#include <time.h>

/*nag��wki*/

/**
 * @brief funkcja wype�niaj�ca tablic� wektor�w
 * @tparam SType - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param toFill - tablica wektor�w kt�r� chcemy wype�ni�
 * @param Size - rozmiar wektor�w
*/
template< typename SType>
void  TabFill(std::vector<SType> toFill[], int Size);

/**
 * @brief przeci��enie TabFill dla tablicy dynamicznej dwuwymiarowej, funkcja wype�niaj�ca tablic�
 * @tparam SType - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna dwuwymiarowa kt�r� chcemy wype�ni�
 * @param Size - ilo�c kolumn tablicy
*/
template <typename SType>
void TabFill(SType** Array, int Size);


/*rozwini�cia nag��wk�w funkcji*/

template< typename SType>
void  TabFill(std::vector<SType> toFill[], int Size) {
	std::cout << "Wylosowano " << ROZMIAR << " tablic " << Size <<" elementowych."<< std::endl;
	srand(time(NULL)); /*Funkcja inicjalizuj�ca funkcj� rand(), przy ka�dym uruchomieniu programu uzyskujemy inn� sekwencj� liczb losowych*/
	
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
	srand((SType)time(NULL));			/*Funkcja inicjalizuj�ca funkcj� rand(), przy ka�dym uruchomieniu programu uzyskujemy inn� sekwencj� liczb losowych*/
	for (int i = 0; i < ROZMIAR; i++)
	{
		Array[i] = new SType[Size];
			for (int j = 0; j < Size; j++)
			{
				Array[i][j] = ((rand() % RANGE) / DECIMAL);
			}
	}
	
}

