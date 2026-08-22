// Problem   : 121. Best Time to Buy and Sell Stock
// Difficulty: Easy
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxProfit = 0;
        for(auto x: prices){
            if(x<mini){
                mini = x;
            }
            else{
                maxProfit = max(maxProfit,x-mini);
            }
        }
        return maxProfit;
    }
};