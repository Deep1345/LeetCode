// Problem   : 494. Target Sum
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Backtracking, Knapsack Problem, 0-1 Knapsack
// URL       : https://leetcode.com/problems/target-sum/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    int count(vector<int>& nums, vector<vector<int>>& dp, int t, int i){
        if(i==0){
            if(nums[i]==0 && t==0){
                return 2;
            }
            else if(nums[i]==t || t==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int NotTake = count(nums,dp,t,i-1);
        int Take = 0;
        if(nums[i]<=t){
            Take = count(nums,dp,t-nums[i],i-1);
        }
        return dp[i][t] = Take+NotTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto x: nums){
            sum += x;
        }
        if(target>sum){
            return 0;
        }
        int t = sum - target;
        if(t%2==1){
            return 0;
        }
        t /= 2;
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        return count(nums,dp,t,n-1);
    }
};