#pragma once

#include <iostream>
#include "Rozmiar.h"
#include <vector>

using namespace std;

/* SortCheck dla wektrów */
template <typename Type>
void SortCheck(vector<Type> toCheck[]) {
	
	int row_check = 0;
	int array_check = 0;
	int boost = 0;
	for (int i = 0; i < ROZMIAR; i++) {
		row_check = 0;										/* Przypisanie licznikowi wierszy posortowanych wartoœci pocz¹tkowej 1 */
		boost = 0;
		for (int j = 0; j < toCheck[i].size()-1; j++) {
			
			if (toCheck[i][j] == toCheck[i][j + 1])
			{
				boost += 1;
			}
			if (toCheck[i][j]<toCheck[i][j+1])
			{
				row_check =row_check + 1;
				
			}
			else if (toCheck[i][j] > toCheck[i][j + 1])
			{
				row_check =row_check - 1 ;
			}
		}

		if (row_check + boost == toCheck[i].size()-1)
		{
			array_check += 1;
		}
		else if (-row_check + boost == toCheck[i].size()-1)
		{
			array_check += -1;
		}
		else
		{
			array_check = 0;
		}

	}
	if (array_check == ROZMIAR)
	{
		cout << endl << "Posortowano: " << array_check << " tablic rosnaco." << endl << endl;
	}
	else if (array_check == -ROZMIAR)
	{
		cout << endl << "Posortowano: " << -array_check << " tablic malejaco." << endl << endl;
	}
	else
	{
		cout << endl << "SortCheck:  CO NAJMNIEJ JEDNA TABLICA NIE JEST POSORTOWANA!" << endl << endl;
	}


}

/* SortCheck dla tablic */
template <typename Type>
void SortCheck(Type** toCheck, int size) {
	int row_check = 0;
	int array_check = 0;
	int boost = 0;
	for (int i = 0; i < ROZMIAR; i++) {
		row_check = 0;										/* Przypisanie licznikowi wierszy posortowanych wartoœci pocz¹tkowej 1 */
		boost = 0;
		for (int j = 0; j < size - 1; j++) {

			if (toCheck[i][j] == toCheck[i][j + 1])
			{
				boost += 1;
			}
			if (toCheck[i][j] < toCheck[i][j + 1])
			{
				row_check = row_check + 1;

			}
			else if (toCheck[i][j] > toCheck[i][j + 1])
			{
				row_check = row_check - 1;
			}
		}

		if (row_check + boost == size - 1)
		{
			array_check += 1;
		}
		else if (-row_check + boost == size - 1)
		{
			array_check += -1;
		}
		else
		{
			array_check = 0;
		}

	}
	if (array_check == ROZMIAR)
	{
		cout << endl << "SortCheck:  Posortowano: " << array_check << " tablic rosnaco." << endl << endl;
	}
	else if (array_check == -ROZMIAR)
	{
		cout << endl << "SortCheck:  Posortowano: " << -array_check << " tablic malejaco." << endl << endl;
	}
	else
	{
		cout << endl << "SortCheck:  CO NAJMNIEJ JEDNA TABLICA NIE JEST POSORTOWANA!" << endl << endl;
	}
}
