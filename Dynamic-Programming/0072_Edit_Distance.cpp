// Problem   : 72. Edit Distance
// Difficulty: Medium
// Tags      : String, Dynamic Programming
// URL       : https://leetcode.com/problems/edit-distance/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    int solve(string& s, string& t,vector<vector<int>>& dp,int i, int j){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j] = solve(s,t,dp,i-1,j-1);
        }
        else{
            return dp[i][j] = 1+min(solve(s,t,dp,i-1,j),min(solve(s,t,dp,i-1,j-1),solve(s,t,dp,i,j-1)));
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(word1,word2,dp,n-1,m-1);
    }
};