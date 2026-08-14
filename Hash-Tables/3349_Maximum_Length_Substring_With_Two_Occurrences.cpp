// Problem   : 3349. Maximum Length Substring With Two Occurrences
// Difficulty: Easy
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
// Language  : Cpp
// Date      : 2026-08-14
//

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>2){
                mpp[s[l]]--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};