// Problem   : 4406. Minimum Days to Score Exactly N Points
// Difficulty: Medium
// Tags      : N/A
// URL       : https://leetcode.com/problems/minimum-days-to-score-exactly-n-points/
// Language  : Cpp
// Date      : 2026-09-12
//

class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int k=1;(k*(k+1))/2<=n;k++){
            int points = k * (k + 1) / 2;
            int remaining = n - points;

            if (remaining == 0) {
                ans = min(ans, k);
            }
            else {
                int days = solve(remaining, dp) + k + 1;
                ans = min(ans, days);
            }
        }
        return dp[n] = ans;
    }
    int minDays(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};