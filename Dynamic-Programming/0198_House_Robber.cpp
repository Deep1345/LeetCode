// Problem   : 198. House Robber
// Difficulty: Medium
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/house-robber/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(vector<int>& dp,vector<int>& nums,int n){
        if(n==0){
            return nums[0];
        }
        if(n==1){
            return max(nums[0],nums[1]);
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int notake = solve(dp,nums,n-1);
        int take = solve(dp,nums,n-2)+nums[n];
        return dp[n] = max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(dp,nums,n-1);
    }
};