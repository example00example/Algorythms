#include <bits/stdc++.h>

//#include "LongArithmetics/LongInt.h"
#include "Sortings/MergeSort.h"
//#include "Sortings/BinarySearch.h"
#include "Tasks/2_3_7.h"
#include "Divide and Conquer/MaxSubarray.h"

int main() {
    ssize_t size;
    std::cin >> size;
    std::vector<int> data(size);
    for (size_t i = 0; i < size; i++)
        std::cin >> data[i];

    MergeSort(data);

    int val;
    std::cin >> val;
    auto result = SearchOfSum(data, val);
    std::cout << "(" << result.first << ", " << result.second << ")" << std::endl;

    return 0;
}