#pragma once

#include <iostream>
#include "Rozmiar.h"
#include <vector>

using namespace std;

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
				cout << " rowne " << boost << endl;
			}
			if (toCheck[i][j]<toCheck[i][j+1])
			{
				row_check =row_check + 1;
				cout << " rosnaca " << row_check << endl;
				
			}
			else if (toCheck[i][j] > toCheck[i][j + 1])
			{
				row_check =row_check - 1 ;
				cout << " mlejaca " <<row_check<< endl;
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
	cout << "array_check " << array_check << endl;
	if (array_check == ROZMIAR)
	{
		cout << endl << "Posortowano: " << array_check << " tablic rosnaco." << endl;
	}
	else if (array_check == -ROZMIAR)
	{
		cout << endl << "Posortowano: " << -array_check << " tablic malejaco." << endl;
	}
	else
	{
		cout << endl << "CO NAJMNIEJ JEDNA TABLICA NIE JEST POSORTOWANA!" << endl;
	}


}

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
				cout << " rowne " << boost << endl;
			}
			if (toCheck[i][j] < toCheck[i][j + 1])
			{
				row_check = row_check + 1;
				cout << " rosnaca " << row_check << endl;

			}
			else if (toCheck[i][j] > toCheck[i][j + 1])
			{
				row_check = row_check - 1;
				cout << " mlejaca " << row_check << endl;
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
	cout << "array_check " << array_check << endl;
	if (array_check == ROZMIAR)
	{
		cout << endl << "Posortowano: " << array_check << " tablic rosnaco." << endl;
	}
	else if (array_check == -ROZMIAR)
	{
		cout << endl << "Posortowano: " << -array_check << " tablic malejaco." << endl;
	}
	else
	{
		cout << endl << "CO NAJMNIEJ JEDNA TABLICA NIE JEST POSORTOWANA!" << endl;
	}
}
