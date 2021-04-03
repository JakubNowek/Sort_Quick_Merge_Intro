#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <typename E>
void Hybrid_Introspective_Sort(std::vector<E>& S, long N)
{
    int maxdepth = (int)floor(2 * log(N));
    IntroSort(S, N, maxdepth);
    Insertion_Sort(S, N);

}

template <typename E>
void IntroSort(std::vector<E> &S, long N, int M){
     long i;
     if (M <= 0)
     {
         Heap_Sort(S, N);
         return;
     }
     i = Partition(S, 0, N);
     if (i > 9) {

         IntroSort(S, i, M - 1);

     }
     if (N - 1 - i > 9) {
         IntroSort(S + i + 1, N - 1 - i, M - 1);
     }
}

template <typename E>
long Partition(std::vector<E>& S, long L, long R)
{
    long i, j;
    if (R >= 3)
        MedianOfThree(S, L, R);
    for (i = L, j = R - 2; ; )
    {
        for (; S[i] < S[R - 1]; ++i);
        for (; j >= L && S[j] > S[R - 1]; --j);
        if (i < j)
            Exchange(S, i++, j--);
        else break;
    }
    Exchange(S, i, R - 1);
    return i;
}

template <typename E>
void MedianOfThree(std::vector<E>& S, long& L, long& R)
{
    if (S[++L - 1] > S[--R])
        Exchange(S, L - 1, R);
    if (S[L - 1] > S[R / 2])
        Exchange(S, L - 1, R / 2);
    if (S[R / 2] > S[R])
        Exchange(S, R / 2, R);
    Exchange(S, R / 2, R - 1);
}

template <typename E>
void Exchange(std::vector<E>& S, long i, long j)
{
    E temp;
    temp = S[i];
    S[i] = S[j];
    S[j] = temp;
}

template <typename E>
void Heap_Sort(std::vector<E>& S, long N)
{
    long i;
    for (i = N / 2; i > 0; --i)
        Heapify(S.begin - 1, i, N);
    for (i = N - 1; i > 0; --i)
    {
        Exchange(S, 0, i);
        Heapify(S.begin - 1, 1, i);
    }
}

template <typename E>
void Heapify(std::vector<E>& S, long i, long N)
{
    long j;
    while (i <= N / 2)
    {
        j = 2 * i;
        if (j + 1 <= N && S[j + 1] > S[j])
            j = j + 1;
        if (S[i] < S[j])
            Exchange(S, i, j);
        else break;
        i = j;
    }
}

template <typename E>
void Insertion_Sort(std::vector<E>& S, long N)
{
    long i, j;
    E temp;
    for (i = 1; i < N; ++i)
    {
        temp = S[i];
        for (j = i; j > 0 && temp < S[j - 1]; --j)
            S[j] = S[j - 1];
        S[j] = temp;
    }
}
