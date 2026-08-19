// Problem   : 28. Find the Index of the First Occurrence in a String
// Difficulty: Easy
// Tags      : Two Pointers, String, String Matching, Z Algorithm, Knuth–Morris–Pratt Algorithm, Boyer–Moore String-Search Algorithm
// URL       : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(j==m-1){
                    return i;
                }
            }
        }
        return -1;
    }
};