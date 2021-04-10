#pragma once

#include <iostream>
#include "Rozmiar.h"
#include <vector>

/*nag³ówki*/

/* SortCheck dla wektrów */
/**
 * @brief funkcja sprawdzaj¹ca, czy tablica wektorów jest posortowana, a jeœli tak, to czy rosn¹co, czy malej¹co
 * @tparam Type - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param toCheck - tablica wektorów któr¹ chcemy sprawdziæ
*/
template <typename Type>
void SortCheck(std::vector<Type> toCheck[]);

/* SortCheck dla tablic */

/**
 * @brief przeci¹¿enie SortCheck, funkcja sprawdzaj¹ca, czy tablica dynamiczna dwuwymiarowa jest posortowana, a jeœli tak, to czy rosn¹co, czy malej¹co
 * @tparam Type - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param toCheck - dwuwymiarowa tablica dynamiczna, któr¹ chcemy sprawdziæ
 * @param size - iloœc kolumn tablicy dynamicznej
*/
template <typename Type>
void SortCheck(Type** toCheck, int size);

/*rozwiniêcia nag³ówków funkcji*/

template <typename Type>
void SortCheck(std::vector<Type> toCheck[]) {
	
	int row_check = 0; // zmienna przechowuj¹ca liczbê posortowanych rosn¹co lub malej¹co elementów wektora
	int array_check = 0; // zmienna przechowuj¹ca liczbê posortowanych rosn¹co lub malej¹co wektorów
	int boost = 0; // zmienna przechowuj¹ca liczbê powtórzeñ elementów w wektorze
	int equal = 0; // zmienna przechowuj¹ca liczbê tablic z identycznymi elementami
	for (int i = 0; i < ROZMIAR; i++) {
		row_check = 0;										
		boost = 0;
		for (int j = 0; j < toCheck[i].size()-1; j++) {
			
			if (toCheck[i][j] == toCheck[i][j+1]) // przypadek , kiedy elementy s¹ równe
			{
				boost += 1;
			}
			if (toCheck[i][j]<toCheck[i][j+1]) // przypadek, kiedy element z prawej jest mniejszy
			{
				row_check =row_check + 1;
				
			}
			else if (toCheck[i][j] > toCheck[i][j+1]) // przypadek, kiedy element z prawej jest wiêkszy
			{
				row_check =row_check - 1 ;
			}
		}
		//warunek posortowania niemalej¹co
		if (row_check + boost == toCheck[i].size()-1 && boost != toCheck[i].size() - 1) // dodanie liczby elementów równych do liczby elementów posortowanych rosn¹co
		{
			array_check += 1;
		}
		//warunek posortowania nierosn¹co
		else if (-row_check + boost == toCheck[i].size()-1 && boost != toCheck[i].size() - 1) // dodanie liczby elementów równych do liczby elementów posortowanych malej¹co
		{
			array_check += -1;
		}
		//warunek równoœci wszystkich elementów
		else if (boost == toCheck[i].size() - 1)
		{
			equal += 1;
		}
		else // warunek nieposortowania
		{
			array_check = 0;
		}

	}
	if (array_check == ROZMIAR)
	{
		std::cout << std::endl << "SortCheck:  Posortowano: " << array_check << " tablic niemalejaco." << std::endl << std::endl;
	}
	else if (array_check == -ROZMIAR)
	{
		std::cout << std::endl << "SortCheck:  Posortowano: " << -array_check << " tablic nierosnaco." << std::endl << std::endl;
	}
	else if (equal != 0)
	{
		std::cout << std::endl << "Ups, " << equal << " tablic(e) wypelniono identycznymi emementami " << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << "SortCheck:  CO NAJMNIEJ JEDNA TABLICA NIE JEST POSORTOWANA!" << std::endl << std::endl;
	}


}


template <typename Type>
void SortCheck(Type** toCheck, int size) {
	int row_check = 0;	// zmienna przechowuj¹ca liczbê posortowanych rosn¹co lub malej¹co elementów tablicy
	int array_check = 0;// zmienna przechowuj¹ca liczbê posortowanych rosn¹co lub malej¹co tablic
	int boost = 0; // zmienna przechowuj¹ca liczbê powtórzeñ elementów w tablicy
	int equal = 0; // zmienna przechowuj¹ca liczbê tablic z identycznymi elementami
	for (int i = 0; i < ROZMIAR; i++) {
		row_check = 0;										/* Przypisanie licznikowi wierszy posortowanych wartoœci pocz¹tkowej 1 */
		boost = 0;
		for (int j = 0; j < size - 1; j++) {

			if (toCheck[i][j] == toCheck[i][j + 1]) // przypadek , kiedy elementy s¹ równe
			{
				boost += 1;
			}
			if (toCheck[i][j] < toCheck[i][j + 1]) // przypadek, kiedy element z prawej jest mniejszy
			{
				row_check = row_check + 1;

			}
			else if (toCheck[i][j] > toCheck[i][j + 1]) // przypadek, kiedy element z prawej jest wiêkszy
			{
				row_check = row_check - 1;
			}
		}
		//warunek posortowania niemalej¹co
		if (row_check + boost == size - 1 && boost != size - 1) // dodanie liczby elementów równych do liczby elementów posortowanych rosn¹co
		{
			array_check += 1;
		}
		//warunek posortowania nierosn¹co
		else if (-row_check + boost == size - 1 && boost != size - 1) // dodanie liczby elementów równych do liczby elementów posortowanych malej¹co
		{
			array_check += -1;
		}
		//warunek równoœci wszystkich elementów
		else if (boost == size - 1) 
		{
			equal += 1;
		}
		else // warunek nieposortowania
		{
			array_check = 0;
		}

	}
	if (array_check == ROZMIAR)
	{
		std::cout << std::endl << "SortCheck:  Posortowano: " << array_check << " tablic(e) niemalejaco." << std::endl << std::endl;
	}
	else if (array_check == -ROZMIAR)
	{
		std::cout << std::endl << "SortCheck:  Posortowano: " << -array_check << " tablic(e) nierosnaco." << std::endl << std::endl;
	}
	else if (equal != 0)
	{
		std::cout << std::endl << "Ups, " << equal << " tablic(e) wypelniono identycznymi emementami " << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << "SortCheck:  CO NAJMNIEJ JEDNA TABLICA NIE JEST POSORTOWANA!" << std::endl << std::endl;
	}
}
