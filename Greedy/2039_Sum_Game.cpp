// Problem   : 2039. Sum Game
// Difficulty: Medium
// Tags      : Math, String, Greedy, Game Theory
// URL       : https://leetcode.com/problems/sum-game/
// Language  : Cpp
// Date      : 2026-08-23
//

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // Odd number of '?' -> Alice always wins
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Otherwise, Bob wins only if the exact balance is possible
        return leftSum - rightSum != 9 * (rightQ - leftQ) / 2;
    }
};