// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
using namespace std;

int main()
{
	cout << "Siema" << endl;
	int size = 10000;
	double proc = 100;				  // procent posortowania tablicy
	double czas_0 = 0, czas_k = 0;
	/* Sortowanie wektorow */

	/* Generowanie i wyświetlanie wektora */
	vector<int> tab[ROZMIAR];
	TabFill(tab,size);
	//Display(tab);
	cout << endl << endl;

	/* max->min */			    
	/* QuickSort dla wektorów */ // sotowanie tablicy stopień posortowania w procentach przekazujemy w parametrze 'proc'
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//_backQuickSort(tab[i],100);
	//}
	

	/* min->max */
	/* MergeSort dla wektorów */
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}
	//czas_k = clock() - czas_0;
	//cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;


	/* min->max */
	/* QuickSort dla wektorów */ // sotowanie tablicy stopień posortowania w procentach przekazujemy w parametrze 'proc'
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//QuickSort(tab[i],proc);
	//}
	//czas_k = clock() - czas_0;
	//cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;



	//Display(tab);



	/* Sortowanie tablicy */


	/* Generowanie i wyświetlanie tablicy */
	int** Array = new int* [ROZMIAR]; // rezerwowanie miejsca na tablicę wskaźników o ilości wierszy ROZMIAR
	TabFill(Array, size);			  // wypełnianie tablicy
	//Display(Array, size);			  // wyświetlanie tablicy
	cout << endl << endl;
	

	/* max->min */
	/* QuickSort dla tablicy (procent posortowania określany w zmiennej 'proc') */
	//for (int i = 0; i < ROZMIAR; i++){
	//_backQuickSort(Array[i], size, proc);
	//}


	/* min->max */
	/* Sortowanie introspektywne (procent posortowania określany w zmiennej 'proc') */
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//	Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;





	/* min->max */
	/* QuickSort dla tablicy (procent posortowania określany w zmiennej 'proc') */
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//QuickSort(Array[i], size, proc);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;



	


	//Display(Array, size);

	//for (int i = 0; i < ROZMIAR; i++)
	//{
	//	delete Array[i];
	//}


	/*
	TODO:	dodać liczenie czasu
			dodać menu
			sprawdzić jak dodać polskie znaki do README
	*/
	return 0;
}
