// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
using namespace std;

int main()
{
	/* Sortowanie wektorow */
	cout << "Siema" << endl;
	vector<int> tab[ROZMIAR];
	int size = 16;
	TabFill(tab,size);
	Display(tab);
	/* MergeSort */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}

	/* QuickSort */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	QuickSort_proc(tab[0],size,25);
	//}
	 
	cout << endl << endl;
	Display(tab);

	/*
	TODO:	dodać opcję zmiany sortowania od max->min (wystarczy dla jednego)
			dodać menu
			sprawdzić jak dodać polskie znaki do README
	*/
	 

	/* Sortowanie tablicy */

	/* Sortowanie introspektywne */
	//int** Array = new int* [ROZMIAR]; // rezerwowanie miejsca na tablicę wskaźników o ilości wierszy ROZMIAR
	//TabFill(Array, size);			  // wypełnianie tablicy
	//Display(Array, size);			  // wyświetlanie tablicy
	//cout << endl << endl;

	//for (int i = 0; i < ROZMIAR; i++){
	//	Hybrid_Introspective_Sort(Array[i], size);
	//}
	//
	//Display(Array, size);
	return 0;
}
