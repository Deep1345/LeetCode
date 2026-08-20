// Problem   : 213. House Robber II
// Difficulty: Medium
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/house-robber-ii/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int n, int start) {
        if(n < start)
            return 0;
        if(n == start)
            return nums[n];
        if(dp[n] != -1)
            return dp[n];
        int take = nums[n] + solve(nums, dp, n-2, start);
        int notake = solve(nums, dp, n-1, start);
        return dp[n] = max(take, notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        // Don't take last
        int case1 = solve(nums, dp1, n-2, 0);
        // Don't take first
        int case2 = solve(nums, dp2, n-1, 1);
        return max(case1, case2);
    }
};