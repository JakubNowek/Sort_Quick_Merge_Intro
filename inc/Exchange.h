#pragma once


/**
 * @brief funkcja odpoiadaj¹ca za zamianê dwóch elementów tablicy dynamicznej 
 * @tparam Type - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna 
 * @param i - numer indeksu elementu tablicy który chcemy zamieniæ
 * @param j - numer indeksu elementu tablicy który chcemy zamieniæ
*/
template <class Type>
void Exchange(Type* Array, long i, long j);

/**
 * @brief funkcja odpoiadaj¹ca za zamianê elementów dwóch tablic dynamicznych (odpowiednik funkcji swap z std dla wektorów)
 * @tparam Type - typ zmiennej umo¿liwiaj¹cy wstawianie dowolnego liczbowego typu danych
 * @param Array1 - pierwsza tablica dynamiczna
 * @param Array2 - druga tablica dynamiczna
 * @param size - zmienna przechowuj¹ca rozmiar tablicy
*/
template <class Type>
void Exchange(Type* Array1, Type* Array2, int size);


template <class Type>
void Exchange(Type* Array, long i, long j)
{
	Type temp;
	temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}

template <class Type>
void Exchange(Type* Array1, Type* Array2, int size)
{
	Type temp; //zmienna pomocnicza, przechowuj¹ca wartoœæ jednego z elementów

	for (int i = 0; i < size ; i++)
	{
		
		temp = Array1[i];
		Array1[i] = Array1[i];
		Array1[i] = temp;
	}
}