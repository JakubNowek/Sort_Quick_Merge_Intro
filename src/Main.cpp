// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
using namespace std;

int main()
{
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
	Display(tab);

	return 0;
}
