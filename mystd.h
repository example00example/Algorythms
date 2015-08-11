//
// Created by leo on 10.08.15.
//
#pragma once
#include <bits/stdc++.h>

#ifndef ALGORYTHMS_MYSTD_H
#define ALGORYTHMS_MYSTD_H

#endif //ALGORYTHMS_MYSTD_H


template<typename T>
std::ostream& operator<<(std::ostream& stream, std::vector<T> data) {
    for (auto cur: data)
        stream << cur << ' ';
    stream << std::endl;
    return stream;
}
