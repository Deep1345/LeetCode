// Problem   : 4245. Count Commas in Range
// Difficulty: Easy
// Tags      : Math
// URL       : https://leetcode.com/problems/count-commas-in-range/
// Language  : Cpp
// Date      : 2026-09-08
//

class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        if(n<=100000){
            return n-1000+1;
        }
        return 0;
    }
};