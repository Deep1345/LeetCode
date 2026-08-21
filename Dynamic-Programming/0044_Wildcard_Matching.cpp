// Problem   : 44. Wildcard Matching
// Difficulty: Hard
// Tags      : String, Dynamic Programming, Greedy, Recursion
// URL       : https://leetcode.com/problems/wildcard-matching/
// Language  : Cpp
// Date      : 2026-08-21
//

class Solution {
public:
    bool check(string& s, string& p,vector<vector<int>>& dp,int i, int j) {
        if(i < 0 && j < 0) {
            return true;
        }
        if(j < 0 && i >= 0) {
            return false;
        }
        if(i < 0 && j >= 0) {
            for(int x = 0; x <= j; x++) {
                if(p[x] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(p[j] == '?' || p[j] == s[i]) {
            return dp[i][j] = check(s, p, dp, i - 1, j - 1);
        }
        if(p[j] == '*') {
            return dp[i][j] = check(s, p, dp, i, j - 1) || check(s, p, dp, i - 1, j);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return check(s, p, dp, n - 1, m - 1);
    }
};