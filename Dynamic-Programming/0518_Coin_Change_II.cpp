// Problem   : 518. Coin Change II
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Knapsack Problem, Complete Knapsack
// URL       : https://leetcode.com/problems/coin-change-ii/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    int count(vector<int>& arr, vector<vector<int>>& dp, int t, int i){
        if(t==0){
            return 1;
        }
        if(i==0){
            if(t%arr[i]==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int NotPick = count(arr,dp,t,i-1);
        int Pick = 0;
        if(arr[i]<=t){
            Pick = count(arr,dp,t-arr[i],i);
        }
        return dp[i][t] = Pick+NotPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return count(coins,dp,amount,n-1);
    }
};