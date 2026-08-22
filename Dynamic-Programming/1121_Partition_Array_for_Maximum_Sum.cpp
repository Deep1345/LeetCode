// Problem   : 1121. Partition Array for Maximum Sum
// Difficulty: Medium
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/partition-array-for-maximum-sum/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int solve(int i,vector<int>& arr, int k,vector<int>& dp){
        int n = arr.size();
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int maxSum = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(arr[j],maxi);
            int sum = (len*maxi)+solve(j+1,arr,k,dp);
            maxSum = max(sum,maxSum);
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(0,arr,k,dp);
    }
};