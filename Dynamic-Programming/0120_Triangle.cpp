// Problem   : 120. Triangle
// Difficulty: Medium
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/triangle/
// Language  : Cpp
// Date      : 2026-08-20
//

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp, int n){
        if(i==n){
            return triangle[i][j];
        }
        if(dp[i][j]!=INT_MAX){
            return dp[i][j];
        }
        int d = triangle[i][j] + solve(i+1,j,triangle,dp,n);
        int dr = triangle[i][j] + solve(i+1,j+1,triangle,dp,n);
        return dp[i][j] = min(d,dr);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,INT_MAX));
        return solve(0,0,triangle,dp,n-1);
    }
};