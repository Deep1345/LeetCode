// Problem   : 3150. Shortest and Lexicographically Smallest Beautiful String
// Difficulty: Medium
// Tags      : String, Sliding Window
// URL       : https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int ones = 0;
        int left = 0;
        int right = 0;
        int start = -1;
        int bestLen = INT_MAX;
        while(right<n){
            if(s[right]=='1'){
                ones++;
            }
            while(ones>k){
                if(s[left]=='1'){
                    ones--;
                }
                left++;
            }
            if (ones == k) {
                while (s[left] == '0')
                    left++;
                int len = right - left + 1;
                if (len < bestLen) {
                    bestLen = len;
                    start = left;
                } 
                else if (len == bestLen) {
                    if (s.substr(left, len) < s.substr(start, bestLen)) {
                        start = left;
                    }
                }
            }
            right++;
        }
        if (start == -1)
            return "";
        return s.substr(start, bestLen);
    }
};