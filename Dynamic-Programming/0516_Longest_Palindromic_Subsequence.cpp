// Problem   : 516. Longest Palindromic Subsequence
// Difficulty: Medium
// Tags      : String, Dynamic Programming
// URL       : https://leetcode.com/problems/longest-palindromic-subsequence/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    int solve(string& s,string& s2,vector<vector<int>>& dp,int i,int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s2[j]){
            return dp[i][j] = 1+solve(s,s2,dp,i-1,j-1);
        }
        else{
            return dp[i][j] = max(solve(s,s2,dp,i,j-1),solve(s,s2,dp,i-1,j));
        }
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s.begin(),s.end());
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,s2,dp,n-1,n-1);
    }
};