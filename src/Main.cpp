// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
#include "Drugi.h"

using namespace std;


int main()
{
	cout << "Siema" << endl;
	vector<int> tab[ROZMIAR];
	int size = 2;
	Drugi(tab,size);
	tab[4][1] = 69;
	for (int i = 0; i < ROZMIAR; i++) {
		for (int j = 0; j < tab[i].size(); j++) {
			printf("%10i ", tab[i][j]);
			//cout<< tab[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
