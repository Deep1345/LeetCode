// Problem   : 1777. Determine if Two Strings Are Close
// Difficulty: Medium
// Tags      : Hash Table, String, Sorting, Counting
// URL       : https://leetcode.com/problems/determine-if-two-strings-are-close/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        int n = word1.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<n;i++){
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0){
                continue;
            }
            else if(freq1[i]==0 && freq2[i]==0){
                continue;
            }
            else{
                return false;
            }
        }
        sort(freq1.begin(),freq1.end());
        sort(begin(freq2),end(freq2));
        if(freq1==freq2){
            return true;
        }
        else{
            return false;
        }
    }
};