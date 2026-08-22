// Problem   : 132. Palindrome Partitioning II
// Difficulty: Hard
// Tags      : String, Dynamic Programming
// URL       : https://leetcode.com/problems/palindrome-partitioning-ii/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    bool ispalindrome(int i, int j, string & s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string& s, vector<int>& dp){
        if(i==s.length()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int mini = INT_MAX;
        for(int j=i;j<s.size();j++){
            if(ispalindrome(i,j,s)){
                int cost = 1 + solve(j+1,s,dp);
                mini = min(mini,cost);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp)-1;

    }
};