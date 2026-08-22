// Problem   : 1669. Minimum Cost to Cut a Stick
// Difficulty: Hard
// Tags      : Array, Dynamic Programming, Sorting
// URL       : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int solve(int i, int j, vector<int>& cuts,vector<vector<int>>& dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for(int k = i; k <= j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + solve(i, k-1, cuts, dp)+ solve(k+1, j, cuts, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int m  = cuts.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, -1));
        return solve(1, cuts.size()-2, cuts, dp);
    }
};