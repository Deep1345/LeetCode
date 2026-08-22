// Problem   : 188. Best Time to Buy and Sell Stock IV
// Difficulty: Hard
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int solve(int i, int buy, int cap,vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(cap==0){
            return 0;
        }
        if(i==arr.size()){
            return 0;
        }
        if(dp[i][buy][cap]!=-1){
            return dp[i][buy][cap];
        }
        int Profit;
        if(buy){
            int Buy = solve(i+1,0,cap,arr,dp)-arr[i];
            int NoBuy = solve(i+1,1,cap,arr,dp);
            Profit = max(Buy,NoBuy);
        }
        else{
            int Sell = solve(i+1,1,cap-1,arr,dp)+arr[i];
            int NoSell = solve(i+1,0,cap,arr,dp);
            Profit = max(Sell,NoSell);
        }
        return dp[i][buy][cap] = Profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);
    }
};