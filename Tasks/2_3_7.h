//
// Created by leo on 12.08.15.
//

#pragma once
#include <bits/stdc++.h>
#include "../Sortings/BinarySearch.h"
#include "../Sortings/MergeSort.h"
#include "../mystd.h"

#ifndef ALGORYTHMS_2_3_7_H
#define ALGORYTHMS_2_3_7_H

#endif //ALGORYTHMS_2_3_7_H

template<typename T>
std::pair<ssize_t, ssize_t> SearchOfSum(std::vector<T> data, T val) {
    /*
     * return position of the pair of numbers whose summary is equal 'val'
     * or (-1, -1) if 'data' doesn't contain required pair
     */
    MergeSort(data);
    ssize_t first, second;
    for (first = 0; data[first] < val; first++) {
        if ((second = BinarySearch(data, val - data[first], first)) != -1) {
            return std::pair<ssize_t, ssize_t>(first, second);
        }
    }
    return std::pair<ssize_t, ssize_t>(-1, -1);
}