#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <class Item>
void Hybrid_Introspective_Sort(Item* Array, long N)
{
    int maxdepth = (int)floor(2 * log(N));
    IntroSort(Array, N, maxdepth);
    Insertion_Sort(Array, N);

}

template <class Item>
void IntroSort(Item* Array, long N, int M)
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

template <class Item>
long Partition(Item* Array, long L, long R)
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

template <class Item>
void MedianOfThree(Item* Array, long& L, long& R)
{
    if (Array[++L - 1] > Array[--R])
        Exchange(Array, L - 1, R);
    if (Array[L - 1] > Array[R / 2])
        Exchange(Array, L - 1, R / 2);
    if (Array[R / 2] > Array[R])
        Exchange(Array, R / 2, R);
    Exchange(Array, R / 2, R - 1);
}

template <class Item>
void Exchange(Item* Array, long i, long j)
{
    Item temp;
    temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}

template <class Item>
void Heap_Sort(Item* Array, long N)
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

template <class Item>
void Heapify(Item* Array, long i, long N)
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

template <class Item>
void Insertion_Sort(Item* Array, long N)
{
    long i, j;
    Item temp;
    for (i = 1; i < N; ++i)
    {
        temp = Array[i];
        for (j = i; j > 0 && temp < Array[j - 1]; --j)
            Array[j] = Array[j - 1];
        Array[j] = temp;
    }
}
