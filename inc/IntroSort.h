#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "Exchange.h"

/*nagłówki funkcji*/

/**
 * @brief funkcja odpowiedzialna za sortowanie, łącząca sortowanie introspektywne i sortowanie przez wstawianie
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param N - zmienna przechowująca ilość kolumn tablicy
*/
template <class Type>
void Hybrid_Introspective_Sort(Type* Array, long N);

/**
 * @brief funkcja rekurencyjna realizująca algorytm sortowania introspektywnego
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param N - zmienna przechowująca rozmiar tablicy dynamicznej
 * @param M - zmienna określajaca maksymalną głębokość rekurencji
*/
template <class Type>
void IntroSort(Type* Array, long N, int M);

/**
 * @brief funkcja odpowiedzialna za podział tablicy na dwa zbiory
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param L - zmienna przechowująca numer indeksu pierwszego elementu tablicy dynamicznej
 * @param R - zmienna przechowująca numer indeksu ostatniego elementu tablicy dynamicznej
 * @return  - funkcja zwraca rozmiar podzbiorów, na które podzielona została tablica
*/
template <class Type>
long Partition(Type* Array, long L, long R);

/**
 * @brief funkcja obliczająca pivot jako medianę z pierwszego , środkowego i ostatniego elementu tablicy
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param L - zmienna przechowująca numer indeksu pierwszego elementu tablicy dynamicznej
 * @param R - zmienna przechowująca numer indeksu ostatniego elementu tablicy dynamicznej
*/
template <class Type>
void MedianOfThree(Type* Array, long& L, long& R);

/**
 * @brief funkcja realizująca algorytm budowanie kopca dla sortowania Heap Sort (sortowanie przez kopcowanie) dla najgorzego scenraiusza QuickSort
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param N - zmienna przechowująca rozmiar tablicy dynamicznej
*/
template <class Type>
void Heap_Sort(Type* Array, long N);

/**
 * @brief funkcja realizująca procedurę rozbierania kopca dla sortowanie przez kopcowanie
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param i - zmienna przechowująca rozmiar kopca
 * @param N - zmienna przechowująca rozmiar tablicy dynamicznej
*/
template <class Type>
void Heapify(Type* Array, long i, long N);

/**
 * @brief funkcja realizująca algorytm sortowania przez wstawianie, używana gdy tablica jest zbyt mała żeby opłacało się sortowanie szybkie
 * @tparam Type - typ zmiennej umożliwiający wstawianie dowolnego liczbowego typu danych
 * @param Array - tablica dynamiczna
 * @param N - zmienna przechowująca rozmiar tablicy dynamicznej
*/
template <class Type>
void Insertion_Sort(Type* Array, long N);


/*rozwinięcia nagłówków funkcji*/

template <class Type>
void Hybrid_Introspective_Sort(Type* Array, long N)
{
    int maxdepth = (int)floor(2 * log(N)); //maksymalna głębokość rekurencji
    IntroSort(Array, N, maxdepth);
    Insertion_Sort(Array, N);

}

template <class Type>
void IntroSort(Type* Array, long N, int M)
{
    long i;
    if (M <= 0)
    {
        Heap_Sort(Array, N);
        return;
    }
    i = Partition(Array, 0, N);
    if (i > 9)
        IntroSort(Array, i, M - 1);
    if (N - 1 - i > 9)
        IntroSort(Array + i + 1, N - 1 - i, M - 1);
}

template <class Type>
long Partition(Type* Array, long L, long R)
{
    long i, j;
    if (R >= 3)
        MedianOfThree(Array, L, R);
    for (i = L, j = R - 2; ; )
    {
        for (; Array[i] < Array[R - 1]; ++i);
        for (; j >= L && Array[j] > Array[R - 1]; --j); 
        if (i < j)
            Exchange(Array, i++, j--);
        else break;
    }
    Exchange(Array, i, R - 1);
    return i;
}

template <class Type>
void MedianOfThree(Type* Array, long& L, long& R)
{
    if (Array[++L - 1] > Array[--R])
        Exchange(Array, L - 1, R);
    if (Array[L - 1] > Array[R / 2])
        Exchange(Array, L - 1, R / 2);
    if (Array[R / 2] > Array[R])
        Exchange(Array, R / 2, R);
    Exchange(Array, R / 2, R - 1);
}

template <class Type>
void Heap_Sort(Type* Array, long N)
{
    long i;
    for (i = N / 2; i > 0; --i)
        Heapify(Array - 1, i, N);
    for (i = N - 1; i > 0; --i)
    {
        Exchange(Array, 0, i);
        Heapify(Array - 1, 1, i);
    }
}

template <class Type>
void Heapify(Type* Array, long i, long N)
{
    long j;
    while (i <= N / 2)
    {
        j = 2 * i;
        if (j + 1 <= N && Array[j + 1] > Array[j]) 
            j = j + 1;
        if (Array[i] < Array[j]) 
            Exchange(Array, i, j);
        else break;
        i = j;
    }
}

template <class Type>
void Insertion_Sort(Type* Array, long N)
{
    long i, j;
    Type temp;
    for (i = 1; i < N; ++i)
    {
        temp = Array[i];
        for (j = i; j > 0 && temp < Array[j - 1]; --j) 
            Array[j] = Array[j - 1];
        Array[j] = temp;
    }
}
