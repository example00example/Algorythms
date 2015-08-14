//
// Created by leo on 13.08.15.
//
#pragma once
#include <bits/stdc++.h>

#ifndef ALGORYTHMS_MAXSUBARRAY_H
#define ALGORYTHMS_MAXSUBARRAY_H

#endif //ALGORYTHMS_MAXSUBARRAY_H

template<typename T>
struct Profit {
    Profit(ssize_t left=0, ssize_t right=0, T profit=T()):
        left_(left),
        right_(right),
        profit_(profit)
    {}

    ssize_t left_, right_;
    T profit_;
};

namespace __MaxSubarray__ {
    template<typename T>
    Profit<T> CenterMaxProfit(const std::vector<T>& data, ssize_t left, ssize_t right, ssize_t border) {
        ssize_t lmax = border;
        T lmaxsum = data[lmax], sum = data[lmax];
        for (ssize_t i = border - 1; i >= left; i--) {
            sum += data[i];
            if (sum > lmaxsum) {
                lmaxsum = sum;
                lmax = i;
            }
        }

        ssize_t rmax = border + 1;
        T rmaxsum = data[rmax];
        sum = data[rmax];
        for (ssize_t i = border + 2; i <= right; i++) {
            sum += data[i];
            if (sum > rmaxsum) {
                rmaxsum = sum;
                rmax = i;
            }
        }

        return Profit<T>(lmax, rmax, lmaxsum + rmaxsum);
    }
}

template<typename T>
Profit<T> MaxSubarray(const std::vector<T>& data, ssize_t left=0, ssize_t right=-1) {
    if (right == -1)
        right = data.size() - 1;
    if (right == left)
        return Profit<T>(left, right, data[left]);

    ssize_t border = (right + left) / 2;
    Profit<T> lmax, rmax, cmax;
    lmax = MaxSubarray(data, left, border);
    rmax = MaxSubarray(data, border + 1, right);
    cmax = __MaxSubarray__::CenterMaxProfit(data, left, right, border);
    if (lmax.profit_ == std::max({lmax.profit_, rmax.profit_, cmax.profit_}))
        return lmax;
    else
        return (rmax.profit_ == std::max({lmax.profit_, rmax.profit_, cmax.profit_})) ? rmax : cmax;
}

template<typename T>
Profit<T> MaxProfit(std::vector<T> data) {
    /*
     * returns such position numbers left and right, that (data[right] - data[left]) is the maximum
     * difference between two elements in 'data' where 'right' is right to 'left'
     */
    for (size_t i = data.size() - 1; i; i--)
        data[i] -= data[i - 1];
    Profit<T> result = MaxSubarray(data, 1);
    result.left_ -= 1;
    return result;
}