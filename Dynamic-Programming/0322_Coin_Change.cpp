// Problem   : 322. Coin Change
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Breadth-First Search, Knapsack Problem, Complete Knapsack
// URL       : https://leetcode.com/problems/coin-change/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    int count(vector<int>& arr, vector<vector<int>>& dp, int i, int target){
        if(i==0){
            if(target%arr[i]==0){
                return target/arr[i];
            }
            else{
                return INT_MAX;
            }
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        long NotPick = count(arr,dp,i-1,target);
        long Pick = INT_MAX;
        if(arr[i]<=target){
            Pick = 1+(long)count(arr,dp,i,target-arr[i]);
        }
        return dp[i][target] = min(Pick,NotPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = count(coins,dp,n-1,amount); 
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};