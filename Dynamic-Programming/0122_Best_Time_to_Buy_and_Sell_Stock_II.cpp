// Problem   : 122. Best Time to Buy and Sell Stock II
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Greedy
// URL       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int solve(vector<int>& arr,vector<vector<int>>& dp, int i, int buy){
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit = 0;
        if(buy==1){
            int Buy = solve(arr,dp,i+1,0) - arr[i];
            int NoBuy = solve(arr,dp,i+1,buy); 
            profit = max(Buy,NoBuy);
        }
        else{
            int Sell = solve(arr,dp,i+1,1) + arr[i];
            int NoSell = solve(arr,dp,i+1,buy);
            profit = max(Sell,NoSell);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = 1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,dp,0,buy);
    }
};