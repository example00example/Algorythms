//
// Created by leo on 11.08.15.
//

#pragma once
#include <bits/stdc++.h>

#ifndef ALGORYTHMS_LONGINT_H
#define ALGORYTHMS_LONGINT_H

// TODO: Add negative integer support
class LongInt {
 public:
    LongInt();
    LongInt(const LongInt&);
    LongInt(const long int);

    LongInt& operator+=(const LongInt&);
    friend const LongInt operator+(LongInt, const LongInt&);

    friend std::ostream& operator<<(std::ostream&, const LongInt&);

 private:
    std::queue<bool> GetBinaryNotation(long);

    std::vector<bool> bits_;
};


#endif //ALGORYTHMS_LONGINT_H
