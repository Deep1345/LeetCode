// Problem   : 309. Best Time to Buy and Sell Stock with Cooldown
// Difficulty: Medium
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int solve(int i,int buy,vector<int>& arr,vector<vector<int>>& dp){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int Profit;
        if(buy){
            int Buy = solve(i+1,0,arr,dp)-arr[i];
            int NoBuy = solve(i+1,1,arr,dp);
            Profit = max(Buy,NoBuy);
        }
        else{
            int Sell = solve(i+2,1,arr,dp)+arr[i];
            int NoSell = solve(i+1,0,arr,dp);
            Profit = max(Sell,NoSell);
        }
        return dp[i][buy] = Profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};