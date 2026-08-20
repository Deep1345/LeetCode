// Problem   : 64. Minimum Path Sum
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Matrix
// URL       : https://leetcode.com/problems/minimum-path-sum/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return mat[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        long long up = mat[i][j] + (long long)solve(i,j-1,mat,dp);
        long long left = mat[i][j] + (long long)solve(i-1,j,mat,dp);
        return dp[i][j] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};