#pragma once

/* Funkcja odpowiadaj�ca za zamian� elementu w tablicy */
template <class Type>
void Exchange(Type* Array, long i, long j)
{
	Type temp;
	temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}
