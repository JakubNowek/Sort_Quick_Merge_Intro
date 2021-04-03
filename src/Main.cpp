// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
using namespace std;

int main()
{
	/* Sortowanie wektorow */
	cout << "Siema" << endl;
	vector<int> tab[ROZMIAR];
	int size = 10;
	TabFill(tab,size);
	Display(tab);
	/* MergeSort */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}

	/* QuickSort */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//QuickSort(tab[i]);
	//}
	 
	cout << endl << endl;
	//Display(tab);

	/*
	TODO:	dodać sortowanie introspektywne - jak przekazać powiększony adres wektora do funkcji
			dodać opcję zmiany sortowania od max->min (wystarczy dla jednego)
			dodać menu
			sprawdzić jak dodać polskie znaki do README
	*/
	 
	/* Sortowanie tablicy */

	int** Array = new int* [ROZMIAR];
	TabFill(Array, size);
	Display(Array, size);

	return 0;
}
