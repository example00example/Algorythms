//
// Created by leo on 12.08.15.
//

#pragma once
#include <bits/stdc++.h>

#ifndef ALGORYTHMS_BINARYSEARCH_H
#define ALGORYTHMS_BINARYSEARCH_H

#endif //ALGORYTHMS_BINARYSEARCH_H

template<typename T>
ssize_t BinarySearch(const std::vector<T> data, T val, ssize_t left=-1, ssize_t right=-1) {
    /*
     * return position number of first occurrence of 'val' in 'data'
     * or -1 if 'data' doesn't contain 'val'
     */
    if (right == -1)
        right = data.size() - 1;
    if (left >= data.size() - 1 || left >= right)
        return -1;

    ssize_t middle = (left + right) / 2;
//    std::cout << "l = " << left << " r = " << right << " m = " << middle << "val = " << val << std::endl;
    while (right - left > 1) {
        if (data[middle] < val) {
            left = middle;
            middle = (right + left) / 2;
        }
        else {
            right = middle;
            middle = (right + left) / 2;
        }
//        std::cout << "l = " << left << " r = " << right << " m = " << middle << std::endl;
    }
    return (data[right] == val) ? right : -1;
}