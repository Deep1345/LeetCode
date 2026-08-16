// Problem   : 2156. Stone Game IX
// Difficulty: Medium
// Tags      : Array, Math, Greedy, Minimax, Counting, Game Theory, Nim Game, Zero-Sum Game
// URL       : https://leetcode.com/problems/stone-game-ix/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int x : stones) {
            cnt[x % 3]++;
        }
        if (cnt[0] % 2 == 0) {
            return min(cnt[1], cnt[2]) > 0;
        }
        return abs(cnt[1] - cnt[2]) > 2;
    }
};