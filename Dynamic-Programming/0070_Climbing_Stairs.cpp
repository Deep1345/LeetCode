// Problem   : 70. Climbing Stairs
// Difficulty: Easy
// Tags      : Math, Dynamic Programming, Memoization
// URL       : https://leetcode.com/problems/climbing-stairs/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0){
            return 1;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int left = solve(n-1,dp);
        int right = solve(n-2,dp);
        return dp[n] = left+right;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};