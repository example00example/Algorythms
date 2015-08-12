#include <bits/stdc++.h>

//#include "LongArithmetics/LongInt.h"
#include "Sortings/MergeSort.h"

int main() {
    ssize_t size;
    std::cin >> size;
    std::vector<int> data(size);
    for (size_t i = 0; i < size; i++)
        std::cin >> data[i];

    MergeSort(data);
    for (auto cur: data)
        std::cout << cur << ' ';

    return 0;
}