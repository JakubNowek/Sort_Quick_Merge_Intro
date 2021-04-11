#pragma once


/**
 * @brief funkcja odpoiadaj�ca za zamian� dw�ch element�w tablicy dynamicznej 
 * @tparam Type - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna 
 * @param i - numer indeksu elementu tablicy kt�ry chcemy zamieni�
 * @param j - numer indeksu elementu tablicy kt�ry chcemy zamieni�
*/
template <class Type>
void Exchange(Type* Array, long i, long j);

/**
 * @brief funkcja odpoiadaj�ca za zamian� element�w dw�ch tablic dynamicznych (odpowiednik funkcji swap z std dla wektor�w)
 * @tparam Type - typ zmiennej umo�liwiaj�cy wstawianie dowolnego liczbowego typu danych
 * @param Array1 - pierwsza tablica dynamiczna
 * @param Array2 - druga tablica dynamiczna
 * @param size - zmienna przechowuj�ca rozmiar tablicy
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
	Type temp; //zmienna pomocnicza, przechowuj�ca warto�� jednego z element�w

	for (int i = 0; i < size ; i++)
	{
		
		temp = Array1[i];
		Array1[i] = Array1[i];
		Array1[i] = temp;
	}
}