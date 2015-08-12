//
// Created by leo on 12.08.15.
//

#pragma once
#include <bits/stdc++.h>

#ifndef ALGORYTHMS_BINARYSEARCH_H
#define ALGORYTHMS_BINARYSEARCH_H

#endif //ALGORYTHMS_BINARYSEARCH_H

template<typename T>
ssize_t BinarySearch(const std::vector<T> data, T val) {
    ssize_t left = -1, right = data.size() - 1, middle = (left + right) / 2;
    std::cout << "l = " << left << " r = " << right << " m = " << middle << std::endl;
    while (right - left > 1) {
        if (data[middle] < val) {
            left = middle;
            middle = (right + left) / 2;
        }
        else {
            right = middle;
            middle = (right + left) / 2;
        }
        std::cout << "l = " << left << " r = " << right << " m = " << middle << std::endl;
    }

    return (data[right] == val) ? right : -1;
}