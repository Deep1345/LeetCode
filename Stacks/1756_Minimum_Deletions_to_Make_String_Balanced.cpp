// Problem   : 1756. Minimum Deletions to Make String Balanced
// Difficulty: Medium
// Tags      : String, Dynamic Programming, Stack
// URL       : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0;
        int del = 0;
        for(char c : s) {
            if(c == 'b') {
                b++;
            }
            else {
                del = min(del + 1, b);
            }
        }
        return del;
    }
};