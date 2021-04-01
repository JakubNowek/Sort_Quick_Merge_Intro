#pragma once

#include <iostream>
#include "Rozmiar.h"
#include "vector"

template <typename T>
class Tab_vec {

	vector<T> table[ROZMIAR];
public:
	vector<T> get_vector(int ind);

};

template <typename T>
 vector<T> Tab_vec<T>::get_vector(int ind) {

	vector<T> out;
	for (int i = 0; i < ROZMIAR; i++) {

		out[i] = table[0][i];
	}
	return out;
}