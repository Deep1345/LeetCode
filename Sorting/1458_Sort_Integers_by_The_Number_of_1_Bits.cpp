// Problem   : 1458. Sort Integers by The Number of 1 Bits
// Difficulty: Easy
// Tags      : Array, Bit Manipulation, Sorting, Counting
// URL       : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [&](int &a, int &b){
            int cntA = __builtin_popcount(a);
            int cntB = __builtin_popcount(b);
            if(cntA==cntB){
                return a<b;
            }
            else{
                return cntA<cntB;
            }
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};