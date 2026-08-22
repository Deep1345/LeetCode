// Problem   : 714. Best Time to Buy and Sell Stock with Transaction Fee
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Greedy
// URL       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int solve(int i, int buy, vector<int>& prices, int fee,vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int Profit;
        if(buy){
            int Buy = solve(i+1,0,prices,fee,dp)-prices[i];
            int NoBuy = solve(i+1,1,prices,fee,dp);
            Profit = max(Buy,NoBuy);
        }
        else{
            int Sell = solve(i+1,1,prices,fee,dp)+prices[i]-fee;
            int NoSell = solve(i+1,0,prices,fee,dp);
            Profit  = max(Sell,NoSell); 
        }
        return dp[i][buy] = Profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,fee,dp);
    }
};