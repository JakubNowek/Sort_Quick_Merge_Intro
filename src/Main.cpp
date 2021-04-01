// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
using namespace std;

int main()
{
	cout << "Siema" << endl;
	vector<int> tab[ROZMIAR];
	int size = 9;
	TabFill(tab,size);
	Display(tab);
	return 0;
}
