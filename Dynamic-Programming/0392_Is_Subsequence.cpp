// Problem   : 392. Is Subsequence
// Difficulty: Easy
// Tags      : Two Pointers, String, Dynamic Programming
// URL       : https://leetcode.com/problems/is-subsequence/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0,j =0;
        while(i<n && j<m){
            if(s[i]==t[j]){
                i++;
            }
            j++;
        }
        if(i==n){
            return true;
        }
        return false;
    }
};