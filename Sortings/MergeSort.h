
//
// Created by leo on 12.08.15.
//

#pragma once
#include <bits/stdc++.h>

#ifndef ALGORYTHMS_MERGESORT_H
#define ALGORYTHMS_MERGESORT_H

#endif //ALGORYTHMS_MERGESORT_H


namespace __MergeSort__ {
    template<typename T>
    void Merge(std::vector<T>& data, ssize_t left, ssize_t right, ssize_t border) {
        std::vector<T> lpart(border - left), rpart(right - border);
        for (ssize_t i = left; i < border; i++)
            lpart[i - left] = data[i];
        for (ssize_t i = border; i < right; i++)
            rpart[i - border] = data[i];

        ssize_t lcur = 0, rcur = 0;
        while (lcur < lpart.size() && rcur < rpart.size()) {
            if (lpart[lcur] < rpart[rcur]) {
                data[left + lcur + rcur] = lpart[lcur];
                lcur++;
            }
            else {
                data[left + lcur + rcur] = rpart[rcur];
                rcur++;
            }
        }
        if (lcur == lpart.size())
            for (; rcur < rpart.size(); rcur++)
                data[left + lcur + rcur] = rpart[rcur];
        else
            for (; lcur < lpart.size(); lcur++)
                data[left + lcur + rcur] = lpart[lcur];
    }
}

template<typename T>
void MergeSort(std::vector<T>& data, ssize_t left=0, ssize_t right=-1) {
    if (right == -1)
        right = data.size();
    if (right - left <= 1)
        return;


    ssize_t border = (left + right) / 2;
    MergeSort(data, left, border);
    MergeSort(data, border, right);
    __MergeSort__::Merge(data, left, right, border);
}
