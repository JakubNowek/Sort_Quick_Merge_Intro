// Main.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "Main.h"
using namespace std;

int main()
{
	cout << "Siema" << endl;
	int size = 15;
	double proc = 100;	 // procent posortowania tablicy
	double czas_0 = 0, czas_k = 0;


	/* Generowanie i wyświetlanie wektora */
	vector<int> tab[ROZMIAR];
	TabFill(tab,size);
	//Display(tab);
	//cout << endl << endl;

	/* Generowanie i wyświetlanie tablicy */
	int** Array = new int* [ROZMIAR]; // rezerwowanie miejsca na tablicę wskaźników o ilości wierszy ROZMIAR
	TabFill(Array, size);			  // wypełnianie tablicy
	//Display(Array, size);
	cout << endl << endl;


	/*Menu*/
	char choice_1[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 1
	char choice_2[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 2
	char choice_3[2] = " "; //tablica znakow zapisujaca wybor uzytkownika poziom 3
	cout << endl << endl << "Witaj kliencie sortowni!" << endl;
	while (choice_1[0] != '0')  /*Poczatek pierwszego switcha*/
	{
	
		cout << "\nJakiego sortowanie Cie interesuje ? :" << endl;
		cout << "  1 - QuickSort  " << endl;
		cout << "  2 - MergeSort  " << endl;
		cout << "  3 - IntroSort  " << endl;
		cout << "  0 - Wypusc mnie!!!! " << endl;
		cout << "Twoj wybor: ";
		cin >> choice_1[0];
		cout << endl << "Wybrales opcje: " << choice_1[0] << endl;
	
		switch (choice_1[0])
		{
			case '1':	while (choice_2[0] != '0') /* Poczatek drugiego switcha */							/* QuickSort */
					{	
						cout << "\nDzialamy na wektorach czy tablicach?"<<endl;
						cout << "  1 - Wektory  " << endl;
						cout << "  2 - Tablice  " << endl;
						cout << "  0 - Cofnij  " << endl;
						cout << "Twoj wybor: ";
						cin >> choice_2[0];
						cout << endl << "Wybrales opcje: " << choice_2[0] << endl << endl;
					
						switch (choice_2[0])
						{
							case '1':   /* quick wektory */cout<<"Quick-Sort - Wektory"<<endl;
								while (choice_3[0] != '0') /* Poczatek trzeciego switcha */
								{
									cout << "\nJakie tablice chcesz sortowac?" << endl;
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
											/* sortowanie wektorow  za pomoca quicksorta */
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										break;
										case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych [1%-100%]:  ";
											cin >> proc; cout << endl;
											/* zapelnianie wektorow funkcja TabFill */
											/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
											cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
											/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										break;
										case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci"<<endl << endl;
											/* zapelnianie wektorow funkcja TabFill */
											/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
											cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (malejaco)" << endl;
											/* sortowanie ponowne posortowanych już wektorow za pomoca quicksorta */
											/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										break;
										case '0': cout << "Cofanie  ";
										break;
										default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
									}
								}
							break;

							case '2':   /*quick tablice*/cout << "Quick-Sort - Tablice"<<endl;
								while (choice_3[0] != '0') 
								{
									cout << "\nJakie tablice chcesz sortowac?" << endl;
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
										/* sortowanie tablic za pomoca quicksorta */
										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										break;
									case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych [1%-100%]:  ";
										cin >> proc; cout << endl;
										/* zapelnianie tablic funkcja TabFill */
										/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
										cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
										/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										break;
									case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
										/* zapelnianie tablic funkcja TabFill */
										/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
										cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (malejaco)" << endl;
										/* sortowanie ponowne posortowanych już tablic za pomoca quicksorta */
										/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
										break;
									case '0': cout << "Cofanie  ";
										break;
									default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
									}
								}
							break;
							case '0':   cout << "Cofanie" << endl; break;
							default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
			break;

			case '2':	while (choice_2[0] != '0') /* Poczatek drugiego switcha */							/* QuickSort */
			{
				cout << "\nDzialamy na wektorach czy tablicach?" << endl;
				cout << "  1 - Wektory  " << endl;
				cout << "  2 - Tablice  " << endl;
				cout << "  0 - Cofnij  " << endl;
				cout << "Twoj wybor: ";
				cin >> choice_2[0];
				cout << endl << "Wybrales opcje: " << choice_2[0] << endl << endl;

				switch (choice_2[0])
				{
				case '1':   /* quick wektory */cout << "Quick-Sort - Wektory" << endl;
					while (choice_3[0] != '0') /* Poczatek trzeciego switcha */
					{
						cout << "\nJakie tablice chcesz sortowac?" << endl;
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
							/* sortowanie wektorow  za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych [1%-100%]:  ";
							cin >> proc; cout << endl;
							/* zapelnianie wektorow funkcja TabFill */
							/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
							/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
							/* zapelnianie wektorow funkcja TabFill */
							/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (malejaco)" << endl;
							/* sortowanie ponowne posortowanych już wektorow za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '0': cout << "Cofanie  ";
							break;
						default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
					break;

				case '2':   /*quick tablice*/cout << "Quick-Sort - Tablice" << endl;
					while (choice_3[0] != '0')
					{
						cout << "\nJakie tablice chcesz sortowac?" << endl;
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
							/* sortowanie tablic za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych [1%-100%]:  ";
							cin >> proc; cout << endl;
							/* zapelnianie tablic funkcja TabFill */
							/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
							/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
							/* zapelnianie tablic funkcja TabFill */
							/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (malejaco)" << endl;
							/* sortowanie ponowne posortowanych już tablic za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '0': cout << "Cofanie  ";
							break;
						default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
					break;
				case '0':   cout << "Cofanie" << endl; break;
				default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
				}
			}
			break;

			case '3':	while (choice_2[0] != '0') /* Poczatek drugiego switcha */							/* QuickSort */
			{
				cout << "\nDzialamy na wektorach czy tablicach?" << endl;
				cout << "  1 - Wektory  " << endl;
				cout << "  2 - Tablice  " << endl;
				cout << "  0 - Cofnij  " << endl;
				cout << "Twoj wybor: ";
				cin >> choice_2[0];
				cout << endl << "Wybrales opcje: " << choice_2[0] << endl << endl;

				switch (choice_2[0])
				{
				case '1':   /* quick wektory */cout << "Quick-Sort - Wektory" << endl;
					while (choice_3[0] != '0') /* Poczatek trzeciego switcha */
					{
						cout << "\nJakie tablice chcesz sortowac?" << endl;
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
							/* sortowanie wektorow  za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych [1%-100%]:  ";
							cin >> proc; cout << endl;
							/* zapelnianie wektorow funkcja TabFill */
							/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
							/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
							/* zapelnianie wektorow funkcja TabFill */
							/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (malejaco)" << endl;
							/* sortowanie ponowne posortowanych już wektorow za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '0': cout << "Cofanie  ";
							break;
						default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
					break;

				case '2':   /*quick tablice*/cout << "Quick-Sort - Tablice" << endl;
					while (choice_3[0] != '0')
					{
						cout << "\nJakie tablice chcesz sortowac?" << endl;
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
							/* sortowanie tablic za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '2': cout << "Podaj ile elementow tabel w '%' ma byc wczesniej posortowanych [1%-100%]:  ";
							cin >> proc; cout << endl;
							/* zapelnianie tablic funkcja TabFill */
							/* sortowanie WSTĘPNE w procentach za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane w " << proc << "% kazda." << endl;
							/* sortowanie ponowne posortowanej już tablicy za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '3': cout << "Sortowanie tablicy posortowanej w odwrotnej kolejnosci" << endl << endl;
							/* zapelnianie tablic funkcja TabFill */
							/* sortowanie WSTĘPNE w odwrotnej kolejnosci (max->min) za pomoca quicksorta */
							cout << "Tablice zostaly wstepnie posortowane by stworzyc najgorszy przypadek (malejaco)" << endl;
							/* sortowanie ponowne posortowanych już tablic za pomoca quicksorta */
							/* sprawdzenie poprawnosci sortowania funkcja sortcheck */
							break;
						case '0': cout << "Cofanie  ";
							break;
						default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
						}
					}
					break;
				case '0':   cout << "Cofanie" << endl; break;
				default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
				}
			}
			break;

			case '0':  cout << endl << "Ewakuacja" << endl;
			break;
	
			default: cout << "NIEROZPOZNANO" << endl; cin.ignore(100000, '\n');   break;
		}
	}



	/*----------------------------------------------------Sortowanie wektorow------------------------------------------------------------------- */


	/* MAX->MIN */	
	/* QuickSort dla wektorów */ // sotowanie tablicy stopień posortowania w procentach przekazujemy w parametrze 'proc'
	//cout << " Tablice posortowane max->min za pomoca OuickSort (wektory)" << endl;
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//_backQuickSort(tab[i],100);
	//}
	

	/* min->max */
	/* MergeSort dla wektorów */
	//cout << "Tablice posortowane min->max za pomoca MergeSort (wektory)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){ //pętla odpowiadająca za sortowanie calej tablicy wektorów
	//MergeSort(tab[i]);
	//}
	//czas_k = clock() - czas_0;
	//cout << endl << "Czas trwania wektorowego: " << czas_k / CLOCKS_PER_SEC << " sekund. " << endl;


	/* min->max */
	/* QuickSort dla wektorów */ // sotowanie tablicy stopień posortowania w procentach przekazujemy w parametrze 'proc'
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
	
	

	/* MAX->MIN */
	/* QuickSort dla tablicy (procent posortowania określany w zmiennej 'proc') */
	//cout << "Tablice posortowana max->min za pomoca OuickSort (tablice*)" << endl;
	//for (int i = 0; i < ROZMIAR; i++){
	//_backQuickSort(Array[i], size, proc);
	//}


	/* min->max */
	/* Sortowanie introspektywne (procent posortowania określany w zmiennej 'proc') */
	//cout << "Tablice posortowana min->max za pomoca IntroSort (tablice*)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//	Hybrid_Introspective_Sort(Array[i], proc*0.01*size);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;


	/* min->max */
	/* QuickSort dla tablicy (procent posortowania określany w zmiennej 'proc') */
	//cout << "Tablice posortowana min->max za pomoca OuickSort (tablice*)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//QuickSort(Array[i], size, proc);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;

	/* min->max */
	/*MergeSort dla tablicy*/
	//cout << "Tablice posortowana min->max za pomoca MergeSort (tablice*)" << endl;
	//czas_0 = clock();
	//for (int i = 0; i < ROZMIAR; i++){
	//MergeSort(Array[i],0,size-1);
	//}
	//czas_k = clock()-czas_0;
	//cout << endl << "Czas trwania tablicowego: " << czas_k/CLOCKS_PER_SEC <<" sekund. "<< endl;

	//Display(Array, size);

	//SortCheck(Array, size);




	/*
	TODO:	dodać menu
	*/

	/* Usuwanie tablic* */
	for (int i = 0; i < ROZMIAR; i++){
		delete Array[i];
	}


	return 0;
}
