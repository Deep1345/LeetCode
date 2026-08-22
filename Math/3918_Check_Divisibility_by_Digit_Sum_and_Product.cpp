// Problem   : 3918. Check Divisibility by Digit Sum and Product
// Difficulty: Easy
// Tags      : Math
// URL       : https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int prod = 1;
        while(n>0){
            int rem = n%10;
            sum += rem;
            prod *= rem;
            n = n/10;
        }
        int total = sum + prod;
        if(temp%total==0){
            return true;
        }
        return false;
    }
};