// Problem   : 1460. Number of Substrings Containing All Three Characters
// Difficulty: Medium
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3] = {0};
        int i = 0;
        int ans = 0;
        for (int j = 0; j < s.size(); j++) {
            cnt[s[j] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += s.size() - j;
                cnt[s[i] - 'a']--;
                i++;
            }
        }
        return ans;
    }
};