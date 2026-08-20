// Problem   : 62. Unique Paths
// Difficulty: Medium
// Tags      : Math, Dynamic Programming, Combinatorics
// URL       : https://leetcode.com/problems/unique-paths/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = solve(i,j-1,dp);
        int left = solve(i-1,j,dp);
        return dp[i][j] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};