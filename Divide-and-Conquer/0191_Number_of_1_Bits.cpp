// Problem   : 191. Number of 1 Bits
// Difficulty: Easy
// Tags      : Divide and Conquer, Bit Manipulation
// URL       : https://leetcode.com/problems/number-of-1-bits/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    int hammingWeight(int n) {
        return __builtin_popcount(n);
    }
};