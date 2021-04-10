#pragma once

#include <iostream>
#include "Rozmiar.h"
#include <vector>

/*nag��wki*/

/* SortCheck dla wektr�w */
/**
 * @brief funkcja sprawdzaj�ca, czy tablica wektor�w jest posortowana, a je�li tak, to czy rosn�co, czy malej�co
 * @tparam Type - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param toCheck - tablica wektor�w kt�r� chcemy sprawdzi�
*/
template <typename Type>
void SortCheck(std::vector<Type> toCheck[]);

/* SortCheck dla tablic */

/**
 * @brief przeci��enie SortCheck, funkcja sprawdzaj�ca, czy tablica dynamiczna dwuwymiarowa jest posortowana, a je�li tak, to czy rosn�co, czy malej�co
 * @tparam Type - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param toCheck - dwuwymiarowa tablica dynamiczna, kt�r� chcemy sprawdzi�
 * @param size - ilo�c kolumn tablicy dynamicznej
*/
template <typename Type>
void SortCheck(Type** toCheck, int size);

/*rozwini�cia nag��wk�w funkcji*/

template <typename Type>
void SortCheck(std::vector<Type> toCheck[]) {
	
	int row_check = 0; // zmienna przechowuj�ca liczb� posortowanych rosn�co lub malej�co element�w wektora
	int array_check = 0; // zmienna przechowuj�ca liczb� posortowanych rosn�co lub malej�co wektor�w
	int boost = 0; // zmienna przechowuj�ca liczb� powt�rze� element�w w wektorze
	int equal = 0; // zmienna przechowuj�ca liczb� tablic z identycznymi elementami
	for (int i = 0; i < ROZMIAR; i++) {
		row_check = 0;										
		boost = 0;
		for (int j = 0; j < toCheck[i].size()-1; j++) {
			
			if (toCheck[i][j] == toCheck[i][j+1]) // przypadek , kiedy elementy s� r�wne
			{
				boost += 1;
			}
			if (toCheck[i][j]<toCheck[i][j+1]) // przypadek, kiedy element z prawej jest mniejszy
			{
				row_check =row_check + 1;
				
			}
			else if (toCheck[i][j] > toCheck[i][j+1]) // przypadek, kiedy element z prawej jest wi�kszy
			{
				row_check =row_check - 1 ;
			}
		}
		//warunek posortowania niemalej�co
		if (row_check + boost == toCheck[i].size()-1 && boost != toCheck[i].size() - 1) // dodanie liczby element�w r�wnych do liczby element�w posortowanych rosn�co
		{
			array_check += 1;
		}
		//warunek posortowania nierosn�co
		else if (-row_check + boost == toCheck[i].size()-1 && boost != toCheck[i].size() - 1) // dodanie liczby element�w r�wnych do liczby element�w posortowanych malej�co
		{
			array_check += -1;
		}
		//warunek r�wno�ci wszystkich element�w
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
	int row_check = 0;	// zmienna przechowuj�ca liczb� posortowanych rosn�co lub malej�co element�w tablicy
	int array_check = 0;// zmienna przechowuj�ca liczb� posortowanych rosn�co lub malej�co tablic
	int boost = 0; // zmienna przechowuj�ca liczb� powt�rze� element�w w tablicy
	int equal = 0; // zmienna przechowuj�ca liczb� tablic z identycznymi elementami
	for (int i = 0; i < ROZMIAR; i++) {
		row_check = 0;										/* Przypisanie licznikowi wierszy posortowanych warto�ci pocz�tkowej 1 */
		boost = 0;
		for (int j = 0; j < size - 1; j++) {

			if (toCheck[i][j] == toCheck[i][j + 1]) // przypadek , kiedy elementy s� r�wne
			{
				boost += 1;
			}
			if (toCheck[i][j] < toCheck[i][j + 1]) // przypadek, kiedy element z prawej jest mniejszy
			{
				row_check = row_check + 1;

			}
			else if (toCheck[i][j] > toCheck[i][j + 1]) // przypadek, kiedy element z prawej jest wi�kszy
			{
				row_check = row_check - 1;
			}
		}
		//warunek posortowania niemalej�co
		if (row_check + boost == size - 1 && boost != size - 1) // dodanie liczby element�w r�wnych do liczby element�w posortowanych rosn�co
		{
			array_check += 1;
		}
		//warunek posortowania nierosn�co
		else if (-row_check + boost == size - 1 && boost != size - 1) // dodanie liczby element�w r�wnych do liczby element�w posortowanych malej�co
		{
			array_check += -1;
		}
		//warunek r�wno�ci wszystkich element�w
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
