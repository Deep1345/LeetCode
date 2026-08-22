// Problem   : 300. Longest Increasing Subsequence
// Difficulty: Medium
// Tags      : Array, Binary Search, Dynamic Programming, Longest Increasing Subsequence
// URL       : https://leetcode.com/problems/longest-increasing-subsequence/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int len(vector<int>& nums,vector<vector<int>>& dp,int i, int prev){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int notTake = len(nums,dp,i+1,prev);
        int take = 0;
        if(prev==-1 || nums[prev]<nums[i]){
            take = len(nums,dp,i+1,i)+1;
        }
        return dp[i][prev+1] = max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return len(nums,dp,0,-1);
    }
};