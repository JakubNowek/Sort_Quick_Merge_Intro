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
	//TabFill(tab,size);
	//Display(tab);
	/* MergeSort */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}

	/* QuickSort */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//QuickSort(tab[i]);
	//}

	/* QuickSort_proc */ //częściowe sotowanie tablicy
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//QuickSort_proc(tab[i],25);
	//}


	cout << endl << endl;
	//Display(tab);

	/*
	TODO:	dodać opcję zmiany sortowania od max->min (wystarczy dla jednego)
			dodać menu
			sprawdzić jak dodać polskie znaki do README
	*/

	/***********************************************************************************************************************************************************8/

	/* Sortowanie tablicy */


	int** Array = new int* [ROZMIAR]; // rezerwowanie miejsca na tablicę wskaźników o ilości wierszy ROZMIAR
	TabFill(Array, size);			  // wypełnianie tablicy
	Display(Array, size);			  // wyświetlanie tablicy
	cout << endl << endl;

	/* Sortowanie introspektywne */
	//for (int i = 0; i < ROZMIAR; i++){
	//	Hybrid_Introspective_Sort(Array[i], size);
	//}
	//


	/* Sortowanie introspektywne dla części tablicy */
	double proc = 0.75;
	for (int i = 0; i < ROZMIAR; i++){
		Hybrid_Introspective_Sort(Array[i],proc*size);
	}
	
	Display(Array, size);

	for (int i = 0; i < ROZMIAR; i++)
	{
		delete Array[i];
	}
	return 0;
}
