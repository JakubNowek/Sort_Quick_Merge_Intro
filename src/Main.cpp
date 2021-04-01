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
	//cout << tab[0][size-2] << endl;
	MergeSort(tab[0]);
	//vector<int> testowy{ 5,4,8,3,4,6,5,3,7};
	/*MergeSort(testowy);
	for (int i = 0; i < testowy.size(); i++)
	{ cout << testowy[i] << " "; }*/
	cout << endl << endl;
	Display(tab);

	return 0;
}
