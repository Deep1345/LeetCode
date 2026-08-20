// Problem   : 63. Unique Paths II
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Matrix
// URL       : https://leetcode.com/problems/unique-paths-ii/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(vector<vector<int>>& mat, vector<vector<int>>& dp,int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        if(mat[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = solve(mat,dp,i,j-1);
        int left = solve(mat,dp,i-1,j);
        return dp[i][j] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(obstacleGrid,dp,n-1,m-1);
    }
};