//
// Created by leo on 10.08.15.
//
#pragma once

#include "InsertionSort.h"

template<typename T>
void InsertionSort(std::vector<T>& data) {
    for (ssize_t i = 1; i < data.size(); i++) {
        T key = data[i];
        ssize_t j = i - 1;
        while (j > -1 and data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}