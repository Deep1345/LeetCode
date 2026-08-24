// Problem   : 2002. Stone Game VIII
// Difficulty: Hard
// Tags      : Array, Math, Dynamic Programming, Minimax, Prefix Sum, Game Theory, Zero-Sum Game
// URL       : https://leetcode.com/problems/stone-game-viii/
// Language  : Cpp
// Date      : 2026-08-24
//

class Solution {
public:
    vector<long long> prefix;
    vector<long long> dp;
    long long solve(int i) {
        // Base case
        if (i == prefix.size() - 1) {
            return prefix[i];
        }
        // Already calculated
        if (dp[i] != LLONG_MIN) {
            return dp[i];
        }
        // Option 1: skip this prefix
        long long skip = solve(i + 1);
        // Option 2: take this prefix
        long long take = prefix[i] - solve(i + 1);
        return dp[i] = max(skip, take);
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        prefix.resize(n);
        prefix[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }
        dp.assign(n, LLONG_MIN);
        return solve(1);
    }
};