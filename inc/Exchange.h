#pragma once

/* Funkcja odpowiadaj¹ca za zamianê elementu w tablicy */
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
	Type temp;

	for (int i = 0; i < size ; i++)
	{
		
		temp = Array1[i];
		Array1[i] = Array1[i];
		Array1[i] = temp;
	}
}