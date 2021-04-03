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
