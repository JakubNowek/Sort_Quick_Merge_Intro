// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"

int main()
{
	/* udostępnienie nazw z przestrzeni std */
	using std::cout;
	using std::endl;
	using std::cin;

	cout << "SORTOWANKO" << endl; //powitanie
	int size = 1000; //rozmiar tablicy (ilość kolumn)
	double proc = 100;	 // procent posortowania tablicy
	double czas_0 = 0, czas_k = 0; //zmienne pomocnicze wykorzystywane do obliczaniu czasu działania algorytmu
	int need_delete = 0; //zmienna pomocnicza, określająca, czy należy usunąć wersy tablicy dynamicznej. 1 - trzeba usunąć, 2 - nie trzeba usuwać


	/* Generowanie i wyświetlanie wektora */
	std::vector<int> tab[ROZMIAR];
	//TabFill(tab,size);
	//Display(tab);
	//cout << endl << endl;

	/* Generowanie i wyświetlanie tablicy */
	int** Array = new int* [ROZMIAR]; // rezerwowanie miejsca na tablicę wskaźników o ilości wierszy ROZMIAR
	//TabFill(Array, size);			  // wypełnianie tablicy
	//Display(Array, size);
	//cout << endl << endl;


	/*Menu*/
	char choice_1[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 1
	char choice_2[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 2
	char choice_3[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 3
	cout << endl << endl << "Witaj kliencie sortowni!" << endl;
	while (choice_1[0] != '0')  /*Poczatek pierwszego switcha*/
	{
		
		cout << "\n Aktualna dlugosc tablicy: " << size << endl;
		cout << "Jakiego sortowanie Cie interesuje ? :" << endl;
		cout << "  1 - QuickSort  " << endl;
		cout << "  2 - MergeSort  " << endl;
		cout << "  3 - IntroSort  " << endl;
		cout << "  4 - Chce zmienic dlugosc tablicy  " << endl;
		cout << "  0 - Wypusc mnie!!!! " << endl;
		cout << "Twoj wybor: ";
		cin >> choice_1[0];
		cout << endl << "Wybrales opcje: " << choice_1[0] << endl<<endl;
	
		switch (choice_1[0])
		{	
			/*QuickSort*/
			case '1':	while (choice_2[0] != '0') /* Poczatek drugiego switcha */							/* QuickSort */
					{	
						cout << "Quick-Sort" << endl;
						cout << "Dzialamy na wektorach czy tablicach?"<<endl;
						cout << "  1 - Wektory  " << endl;
						cout << "  2 - Tablice  " << endl;
						cout << "  0 - Cofnij  " << endl;
						cout << "Twoj wybor: ";
						cin >> choice_2[0];
						cout << endl << "Wybrales opcje: " << choice_2[0] << endl << endl;
					
						switch (choice_2[0])
						{
							case '1':   /* quick wektory */
								while (choice_3[0] != '0') /* Poczatek trzeciego switcha */
								{
									cout << "Quick-Sort - Wektory" << endl;
									cout << "Jakie tablice chcesz sortowac?" << endl;
									cout << "  1 - Zapelnione losowo  " << endl;
									cout << "  2 - Posortowane czesciowo  " << endl;
									cout << "  3 - Posortowane w odwrotnej kolejnosci  " << endl;
									cout << "  0 - Cofnij  " << endl;
									cout << "Twoj wybor: ";
									cin >> choice_3[0];
									cout << endl << "Wybrales opcje: " << choice_3[0] << endl << endl;

									switch (choice_3[0])
									{
									case '1': cout << "Zapelnianie losowe  " << endl;
											/* zapelnianie wektorow funkcja TabFill */
											TabFill(tab,size);											
											
											/* QuickSort dla wektorów */ /* min->max */
											cout << "Tablice posortowane min->max za pomoca OuickSort (wektory)" << endl;
											czas_0 = clock();
											for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
											QuickSort(tab[i],proc);
											}
											czas_k = clock() - czas_0;
											cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
											SortCheck(tab);
										break;
										case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych (0% ; 100%]:  ";
											cin >> proc; cout << endl;
											/* zapelnianie wektorow funkcja TabFill */
											TabFill(tab,size);
											/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
											
											// QuickSort dla wektorów  min->max 
											cout << "Tablice posortowane min->max za pomoca OuickSort (wektory)" << endl;
											for (int i = 0; i < ROZMIAR; i++) { //pętla odpowiadająca za sortowanie calej tablicy wektorów
												QuickSort(tab[i], proc);
											}
											cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
											proc = 100; //powrót do początkowej wartości procentowej
											
											/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */

											/* QuickSort dla wektorów */ 	/* min->max */
											cout << "Tablice posortowane min->max za pomoca OuickSort (wektory)" << endl;
											czas_0 = clock();
											for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
											QuickSort(tab[i],proc);
											}
											czas_k = clock() - czas_0;
											cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
											SortCheck(tab);
										break;
										case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci"<<endl << endl;
											/* zapelnianie wektorow funkcja TabFill */
											TabFill(tab, size);
											/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */

											/* QuickSort dla wektorów */ 	/* MAX->MIN */
											cout << "Tablice posortowane max->min za pomoca MergeSort (wektory)" << endl;
											for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
											_backMergeSort(tab[i]);
											}
											cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (nierosnaco)" << endl;
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
											SortCheck(tab);

											/* sortowanie ponowne posortowanych już wektorow za pomoca quicksorta */

											// QuickSort dla wektorów min->max 
											cout << "Tablice posortowane min->max za pomoca OuickSort (wektory)" << endl;
											czas_0 = clock();
											for (int i = 0; i < ROZMIAR; i++) { //pętla odpowiadająca za sortowanie calej tablicy wektorów
												QuickSort(tab[i], proc);
											}
											czas_k = clock() - czas_0;
											cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
											SortCheck(tab);

										break;
										case '0': cout << "Cofanie  ";
										break;
										default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
									}
								}
							choice_3[0] = ' ';
							break;

							case '2':   /*quick tablice*/
								while (choice_3[0] != '0') 
								{	
									cout << "Quick-Sort - Tablice" << endl;
									cout << "Jakie tablice chcesz sortowac?" << endl;
									cout << "  1 - Zapelnione losowo  " << endl;
									cout << "  2 - Posortowane czesciowo  " << endl;
									cout << "  3 - Posortowane w odwrotnej kolejnosci  " << endl;
									cout << "  0 - Cofnij  " << endl;
									cout << "Twoj wybor: ";
									cin >> choice_3[0];
									cout << endl << "Wybrales opcje: " << choice_3[0] << endl << endl;

									switch (choice_3[0])
									{
									case '1': cout << "Zapelnianie losowe  " << endl;
										/* zapelnianie tablic funkcja TabFill */
										TabFill(Array, size);
										need_delete = 1;
										/* sortowanie tablic za pomoca quicksorta */
										// QuickSort dla tablicy min->max 
										cout << "Tablice posortowana min->max za pomoca OuickSort (tablice*)" << endl;
										czas_0 = clock();
										for (int i = 0; i < ROZMIAR; i++){
										//QuickSort(Array[i], size, proc);
											QuickSort(Array[i], 0, size);
										}
										czas_k = clock()-czas_0;
										cout << endl << "Czas trwania sortowania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;

										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										SortCheck(Array, size);
										break;
									case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych (0% ; 100%]:  ";
										cin >> proc; cout << endl; // wczytwanie wartości procentowego posortowania
										/* zapelnianie tablic funkcja TabFill */
										TabFill(Array, size);
										need_delete = 1;
										/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
										// QuickSort dla tablicy min->max 
										cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
										for (int i = 0; i < ROZMIAR; i++) {
											Hybrid_Introspective_Sort(Array[i], proc * 0.01 * size);
										}
										cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
										proc = 100; //powrót do pierwotnej wartości procentowej
										/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
										// QuickSort dla tablicy min->max 
										cout << "Tablice posortowana min->max za pomoca OuickSort (tablice*)" << endl;
										czas_0 = clock();
										for (int i = 0; i < ROZMIAR; i++){
											//QuickSort(Array[i], size, proc);
											QuickSort(Array[i], 0, size);
										}
										czas_k = clock()-czas_0;
										cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;
										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										SortCheck(Array, size);
										break;
									case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
										/* zapelnianie tablic funkcja TabFill */
										TabFill(Array, size);
										need_delete = 1;
										/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */										
										// QuickSort dla tablicy  MAX->MIN 
										cout << "Tablice posortowana max->min za pomoca MergeSort (tablice*)" << endl;
										for (int i = 0; i < ROZMIAR; i++){
										_backMergeSort(Array[i], 0, size-1);
										}
										cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (nierosnaco)" << endl;
										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										SortCheck(Array,size);

										/* sortowanie ponowne posortowanych już tablic za pomoca quicksorta */
										// QuickSort dla tablicy min->max 
										cout << "Tablice posortowana min->max za pomoca OuickSort (tablice*)" << endl;
										czas_0 = clock();
										for (int i = 0; i < ROZMIAR; i++) {
											//QuickSort(Array[i], size, proc);
											QuickSort(Array[i], 0, size);
										}
										czas_k = clock() - czas_0;
										cout << endl << "Czas trwania tablicowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										SortCheck(Array, size);
										break;
									case '0': cout << "Cofanie  ";
										break;
									default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
									}
								}
							choice_3[0] = ' ';
							break;

							case '0':   cout << "Cofanie" << endl; 
							choice_3[0] = ' '; 
							break;

							default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
			choice_2[0] = ' '; /*czyszczenie wyboru użytkownika*/
			break;

			/*MergeSort*/
			case '2':	while (choice_2[0] != '0') 							/* MergeSort */
			{
				cout << "Merge-Sort" << endl;
				cout << "Dzialamy na wektorach czy tablicach?" << endl;
				cout << "  1 - Wektory  " << endl;
				cout << "  2 - Tablice  " << endl;
				cout << "  0 - Cofnij  " << endl;
				cout << "Twoj wybor: ";
				cin >> choice_2[0];
				cout << endl << "Wybrales opcje: " << choice_2[0] << endl << endl;

				switch (choice_2[0])
				{
				case '1':   /* merge wektory */
					while (choice_3[0] != '0') /* Poczatek trzeciego switcha */
					{
						cout << "Merge-Sort - Wektory" << endl;
						cout << "Jakie tablice chcesz sortowac?" << endl;
						cout << "  1 - Zapelnione losowo  " << endl;
						cout << "  2 - Posortowane czesciowo  " << endl;
						cout << "  3 - Posortowane w odwrotnej kolejnosci  " << endl;
						cout << "  0 - Cofnij  " << endl;
						cout << "Twoj wybor: ";
						cin >> choice_3[0];
						cout << endl << "Wybrales opcje: " << choice_3[0] << endl << endl;

						switch (choice_3[0])
						{
						case '1': cout << "Zapelnianie losowe  " << endl;
							/* zapelnianie wektorow funkcja TabFill */
							TabFill(tab, size);
							/* sortowanie wektorow  za pomoca mergesorta */								
							// MergeSort dla wektorów  min->max 
							cout << "Tablice posortowane min->max za pomoca MergeSort (wektory)" << endl;
							czas_0 = clock();
							for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
							MergeSort(tab[i]);
							}
							czas_k = clock() - czas_0;
							cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(tab);
							break;
						case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych (0% ; 100%]:  ";
							cin >> proc; cout << endl;
							/* zapelnianie wektorow funkcja TabFill */
							TabFill(tab, size);
							/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
							// QuickSort dla wektorów  min->max 
							cout << "Tablice posortowane min->max za pomoca OuickSort (wektory)" << endl;
							for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
							QuickSort(tab[i],proc);
							}
							cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
							proc = 100;
							/* sortowanie ponowne posortowanej już tablicy za pomoca mergesorta */								
							//MergeSort dla wektorów min->max 
							cout << "Tablice posortowane min->max za pomoca MergeSort (wektory)" << endl;
							czas_0 = clock();
							for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
							MergeSort(tab[i]);
							}
							czas_k = clock() - czas_0;
							cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(tab);
							break;
						case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
							/* zapelnianie wektorow funkcja TabFill */
							TabFill(tab, size);
							/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
							// QuickSort dla wektorów MAX->MIN 
							cout << " Tablice posortowane max->min za pomoca MergeSort (wektory)" << endl;
							for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
							_backMergeSort(tab[i]);
							}
							cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (nierosnaco)" << endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(tab);
							/* sortowanie ponowne posortowanych już wektorow za pomoca mergesorta */								
							// MergeSort dla wektorów min->max 
							cout << "Tablice posortowane min->max za pomoca MergeSort (wektory)" << endl;
							czas_0 = clock();
							for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
							MergeSort(tab[i]);
							}
							czas_k = clock() - czas_0;
							cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(tab);
							break;
						case '0': cout << "Cofanie  ";
							break;
						default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
				choice_3[0] = ' ';
				break;

				case '2':   /*merge tablice*/
					while (choice_3[0] != '0')
					{
						cout << "Merge-Sort - Tablice" << endl;
						cout << "Jakie tablice chcesz sortowac?" << endl;
						cout << "  1 - Zapelnione losowo  " << endl;
						cout << "  2 - Posortowane czesciowo  " << endl;
						cout << "  3 - Posortowane w odwrotnej kolejnosci  " << endl;
						cout << "  0 - Cofnij  " << endl;
						cout << "Twoj wybor: ";
						cin >> choice_3[0];
						cout << endl << "Wybrales opcje: " << choice_3[0] << endl << endl;

						switch (choice_3[0])
						{
						case '1': cout << "Zapelnianie losowe  " << endl;
							/* zapelnianie tablic funkcja TabFill */
							TabFill(Array, size);
							need_delete = 1;
							/* sortowanie tablic za pomoca mergesorta */							
							//MergeSort dla tablicy min->max 
							cout << "Tablice posortowana min->max za pomoca MergeSort (tablice*)" << endl;
							czas_0 = clock();
							for (int i = 0; i < ROZMIAR; i++){
							MergeSort(Array[i],0,size-1);
							}
							czas_k = clock()-czas_0;
							cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(Array, size);
							break;
						case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych (0% ; 100%]:  ";
							cin >> proc; cout << endl;
							/* zapelnianie tablic funkcja TabFill */
							TabFill(Array, size);
							need_delete = 1;
							/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
							// QuickSort dla tablicy min->max 
							cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
							for (int i = 0; i < ROZMIAR; i++){
								Hybrid_Introspective_Sort(Array[i], proc * 0.01 * size);
							}
							cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
							proc = 100;
							/* sortowanie ponowne posortowanej już tablicy za pomoca mergesorta */
							//MergeSort dla tablicy min->max 
							cout << "Tablice posortowana min->max za pomoca MergeSort (tablice*)" << endl;
							czas_0 = clock();
							for (int i = 0; i < ROZMIAR; i++) {
								MergeSort(Array[i], 0, size - 1);
							}
							czas_k = clock() - czas_0;
							cout << endl << "Czas trwania tablicowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(Array, size);
							break;
						case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
							/* zapelnianie tablic funkcja TabFill */
							TabFill(Array, size);
							need_delete = 1;
							/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */	
							// QuickSort dla tablicy MAX->MIN 
							cout << "Tablice posortowana max->min za pomoca MergeSort (tablice*)" << endl;
							for (int i = 0; i < ROZMIAR; i++){
							_backMergeSort(Array[i], 0, size-1);
							}
							cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (nierosnaco)" << endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(Array, size);
							/* sortowanie ponowne posortowanych już tablic za pomoca mergesorta */							
							// MergeSort dla tablicy min->max
							cout << "Tablice posortowana min->max za pomoca MergeSort (tablice*)" << endl;
							czas_0 = clock();
							for (int i = 0; i < ROZMIAR; i++){
							MergeSort(Array[i],0,size-1);
							}
							czas_k = clock()-czas_0;
							cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							SortCheck(Array, size);
							break;
						case '0': cout << "Cofanie  ";
							break;
						default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
				choice_3[0] = ' ';
				break;

				case '0':   cout << "Cofanie" << endl;
				choice_3[0] = ' ';
				break;

				default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
				}
			}
			choice_2[0] = ' '; /*czyszczenie wyboru użytkownika*/
			break;

			/*IntroSort*/
			case '3':   while (choice_3[0] != '0')							/*Introsort*/
				{
					cout << "Intro-Sort" << endl;
					cout << "Jakie tablice chcesz sortowac?" << endl;
					cout << "  1 - Zapelnione losowo  " << endl;
					cout << "  2 - Posortowane czesciowo  " << endl;
					cout << "  3 - Posortowane w odwrotnej kolejnosci  " << endl;
					cout << "  0 - Cofnij  " << endl;
					cout << "Twoj wybor: ";
					cin >> choice_3[0];
					cout << endl << "Wybrales opcje: " << choice_3[0] << endl << endl;

					switch (choice_3[0])
					{
					case '1': cout << "Zapelnianie losowe  " << endl;
						/* zapelnianie tablic funkcja TabFill */
						TabFill(Array, size);
						need_delete = 1;
						/* sortowanie tablic za pomoca introsorta */						
						// Sortowanie introspektywne min->max 
						cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
						czas_0 = clock();
						for (int i = 0; i < ROZMIAR; i++){
							Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
						}
						czas_k = clock()-czas_0;
						cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;
						/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
						SortCheck(Array, size);
						break;
					case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych (0% ; 100%]:  ";
						cin >> proc; cout << endl;
						/* zapelnianie tablic funkcja TabFill */
						TabFill(Array, size);
						need_delete = 1;
						/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
						// QuickSort dla tablicy min->max 
						cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
						for (int i = 0; i < ROZMIAR; i++){
							Hybrid_Introspective_Sort(Array[i], proc * 0.01 * size);
						}
						cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
						proc = 100;
						/* sortowanie ponowne posortowanej już tablicy za pomoca introsorta */						
						// Sortowanie introspektywne min->max 
						cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
						czas_0 = clock();
						for (int i = 0; i < ROZMIAR; i++){
							Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
						}
						czas_k = clock()-czas_0;
						cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;
						/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
						SortCheck(Array, size);
						break;
					case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
						/* zapelnianie tablic funkcja TabFill */
						TabFill(Array, size);
						need_delete = 1;
						/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */						
						// QuickSort dla tablicy MAX->MIN 
						cout << "Tablice posortowana max->min za pomoca MergeSort (tablice*)" << endl;
						for (int i = 0; i < ROZMIAR; i++){
						_backMergeSort(Array[i], 0, size-1);
						}
						cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (nierosnaco)" << endl;
						/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
						SortCheck(Array, size);
						/* sortowanie ponowne posortowanych już tablic za pomoca introsorta */							
						// Sortowanie introspektywne min->max
						cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
						czas_0 = clock();
						for (int i = 0; i < ROZMIAR; i++){
							Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
						}
						czas_k = clock()-czas_0;
						cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;
						/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
						SortCheck(Array, size);
						break;
					case '0': cout << "Cofanie  " << endl;
						break;
					default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
					}
				}
				choice_3[0] = ' ';
			choice_2[0] = ' '; /*czyszczenie wyboru użytkownika*/
			break;

			/*Zmiana długości tablicy*/
			case '4': cout << "Podaj dlugosc tablicy: ";
				cin >> size;
				cout << endl;
			choice_2[0] = ' '; /*czyszczenie wyboru użytkownika*/
				break;

			/*Kończenie programu*/
			case '0':  cout << endl << "Ewakuacja" << endl;
			choice_2[0] = ' '; /*czyszczenie wyboru użytkownika*/
			break;
	
			default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
		}
	}



	/*----------------------------------------------------Sortowanie wektorow------------------------------------------------------------------- */



	/* QuickSort dla wektorów */ 	/* MAX->MIN */	
	//cout << " Tablice posortowane max->min za pomoca OuickSort (wektory)" << endl;
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//_backQuickSort(tab[i],100);
	//}
	

	/* MergeSort dla wektorów */	/* min->max */
	//cout << "Tablice posortowane min->max za pomoca MergeSort (wektory)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}
	//czas_k = clock() - czas_0;
	//cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;


	/* QuickSort dla wektorów */ 	/* min->max */
	//cout << "Tablice posortowane min->max za pomoca OuickSort (wektory)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//QuickSort(tab[i],proc);
	//}
	//czas_k = clock() - czas_0;
	//cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;

	//Display(tab);

	//SortCheck(tab);


/*----------------------------------------------------Sortowanie tablic*------------------------------------------------------------------- */


	//Display(Array, size);			  // wyświetlanie tablicy
		
	/* QuickSort dla tablicy */	/* MAX->MIN */
	//cout << "Tablice posortowana max->min za pomoca OuickSort (tablice*)" << endl;
	//for (int i = 0; i < ROZMIAR; i++){
	//_backQuickSort(Array[i], size, proc);
	//}


	/* Sortowanie introspektywne */	/* min->max */
	//cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//	Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;


	/* QuickSort dla tablicy */ /* min->max */
	//cout << "Tablice posortowana min->max za pomoca OuickSort (tablice*)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//QuickSort(Array[i], size, proc);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;


	/*MergeSort dla tablicy*/	/* min->max */
	//cout << "Tablice posortowana min->max za pomoca MergeSort (tablice*)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//MergeSort(Array[i],0,size-1);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;

	//Display(Array, size);

	//SortCheck(Array, size);


	/* Usuwanie tablic* */
	if (need_delete == 1)
	{
		for (int i = 0; i < ROZMIAR; i++) {
			delete[] Array[i];
		}
	}
	delete[] Array;
	
	return 0;
}
