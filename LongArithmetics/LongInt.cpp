//
// Created by leo on 11.08.15.
//

#include "LongInt.h"

LongInt::LongInt():
        bits_(std::vector<bool>({0,0}))
{}

LongInt::LongInt(const LongInt& num):
        bits_(num.bits_)
{}

LongInt::LongInt(const long int num):
        bits_(std::vector<bool>(1, 0)) {
    std::queue<bool> bits = GetBinaryNotation(num);
    while (!bits.empty()) {
        bits_.push_back(bits.front());
        bits.pop();
    }
}

LongInt& LongInt::operator+=(const LongInt& right) {
    bits_.resize(std::max(bits_.size(), right.bits_.size()) + 1);
    bool overflow = false;
    for (size_t i = 1; i < right.bits_.size(); i++) {
        if (overflow) {
            overflow = bits_[i] || right.bits_[i];
            bits_[i] = bits_[i] == right.bits_[i];
        }
        else {
            overflow = bits_[i] && right.bits_[i];
            bits_[i] = bits_[i] != right.bits_[i];
        }
    }
    if (overflow)
        bits_[bits_.size() - 1] = 1;

    return *this;
}

const LongInt operator+(LongInt left, const LongInt& right) {
    return (left += right);
}

std::ostream& operator<<(std::ostream& stream, const LongInt& num) {
    for (size_t i = 1; i < num.bits_.size(); i++)
        stream << num.bits_[i];

    return stream;
}

std::queue<bool> LongInt::GetBinaryNotation(long int num) {
    /*
     * Return stack contains reversed binary notation of 'num'
     * 'num' will be positive integer
     */
    std::queue<bool> result;
    do {
        result.push(num % 2);
        num /= 2;
    } while (num);

    return result;
}