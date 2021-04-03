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


	/* MergeSort dla wektorów */
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}


	/* QuickSort dla wektorów */ // sotowanie tablicy stopień posortowania w procentach przekazujemy w parametrze 'proc'
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//QuickSort(tab[i],100);
	//}


	//cout << endl << endl;
	//Display(tab);



	/* Sortowanie tablicy */


	int** Array = new int* [ROZMIAR]; // rezerwowanie miejsca na tablicę wskaźników o ilości wierszy ROZMIAR
	TabFill(Array, size);			  // wypełnianie tablicy
	Display(Array, size);			  // wyświetlanie tablicy
	cout << endl << endl;
	double proc = 100;				  // procent posortowania tablicy

	/* Sortowanie introspektywne (procent posortowania określany w zmiennej 'proc') */
	//for (int i = 0; i < ROZMIAR; i++){
	//	Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
	//}
	

	/* QuickSort dla tablicy (procent posortowania określany w zmiennej 'proc') */
	//for (int i = 0; i < ROZMIAR; i++){
	//QuickSort(Array[i], size, proc);
	//}

	//Display(Array, size);

	//for (int i = 0; i < ROZMIAR; i++)
	//{
	//	delete Array[i];
	//}


	/*
	TODO:	dodać opcję zmiany sortowania od max->min (wystarczy dla jednego)
			dodać menu
			sprawdzić jak dodać polskie znaki do README
	*/
	return 0;
}
