// Problem   : 1685. Stone Game V
// Difficulty: Hard
// Tags      : Array, Math, Dynamic Programming, Game Theory
// URL       : https://leetcode.com/problems/stone-game-v/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    int solve(int l, int r, vector<int>& prefix, vector<vector<int>>& dp) {
        if (l >= r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        for (int i = l; i < r; i++) {
            int leftSum = prefix[i + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[i + 1];
            if (leftSum < rightSum) {
                ans = max(ans,leftSum + solve(l, i, prefix, dp));
            }
            else if (rightSum < leftSum) {
                ans = max(ans,rightSum + solve(i + 1, r, prefix, dp));
            }
            else {
                ans = max(ans,leftSum + max(solve(l, i, prefix, dp),solve(i + 1, r, prefix, dp)));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, prefix, dp);
    }
};