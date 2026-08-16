// Problem   : 567. Permutation in String
// Difficulty: Medium
// Tags      : Hash Table, Two Pointers, String, Sliding Window
// URL       : https://leetcode.com/problems/permutation-in-string/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m){
            return false;
        }
        vector<int> hash1(26,0);
        vector<int> hash2(26,0);
        for(int i=0;i<n;i++){
            hash1[s1[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            hash2[s2[i]-'a']++;
            if(i>=n){
                hash2[s2[i-n]-'a']--;
            }
            if(hash1==hash2){
                return true;
            }
        }
        return false;
    }
};