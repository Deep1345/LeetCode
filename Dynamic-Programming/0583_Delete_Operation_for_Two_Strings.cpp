// Problem   : 583. Delete Operation for Two Strings
// Difficulty: Medium
// Tags      : String, Dynamic Programming, Longest Common Subsequence
// URL       : https://leetcode.com/problems/delete-operation-for-two-strings/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    int LCS(string& word1, string& word2,vector<vector<int>>& dp,int i, int j){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j] = 1 + LCS(word1,word2,dp,i-1,j-1);
        }
        else{
            return dp[i][j] = max(LCS(word1,word2,dp,i,j-1),LCS(word1,word2,dp,i-1,j));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int k = LCS(word1,word2,dp,n-1,m-1);
        int ans = n + m - (2*k);
        return ans;
    }
};