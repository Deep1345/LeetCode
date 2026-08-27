// Problem   : 4020. Lexicographically Smallest Permutation Greater Than Target
// Difficulty: Medium
// Tags      : Hash Table, String, Greedy, Counting, Enumeration
// URL       : https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
// Language  : Cpp
// Date      : 2026-08-27
//

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> left(26, 0);

        // Characters available from s
        for (char c : s) {
            left[c - 'a']++;
        }

        // Try to match target completely.
        // left[c] can become negative if target
        // needs more copies than s has.
        for (int i = 0; i < n; i++) {
            left[target[i] - 'a']--;
        }

        // Start from the rightmost position.
        for (int i = n - 1; i >= 0; i--) {

            int x = target[i] - 'a';

            // We are no longer forcing target[i] to be equal,
            // so return this character back to available chars.
            left[x]++;

            // Check whether target[0 ... i-1] can be matched.
            bool possible = true;

            for (int c = 0; c < 26; c++) {
                if (left[c] < 0) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Find the smallest character > target[i].
            for (int c = x + 1; c < 26; c++) {

                if (left[c] > 0) {

                    string ans = target.substr(0, i);

                    // Make position i slightly larger.
                    ans += char('a' + c);

                    left[c]--;

                    // Remaining characters in sorted order.
                    for (int j = 0; j < 26; j++) {
                        while (left[j] > 0) {
                            ans += char('a' + j);
                            left[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};