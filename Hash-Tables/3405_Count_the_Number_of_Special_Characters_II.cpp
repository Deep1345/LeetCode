// Problem   : 3405. Count the Number of Special Characters II
// Difficulty: Medium
// Tags      : Hash Table, String
// URL       : https://leetcode.com/problems/count-the-number-of-special-characters-ii/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26,-1);
        vector<int> higher(26,-1);
        int n = word.size();
        for(int i=0;i<n;i++){
            char c = word[i];
            if(islower(c)){
                lower[c-'a'] = i;
            }
            else{
                if(higher[c-'A']==-1){
                    higher[c-'A'] = i;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && higher[i]!=-1 && lower[i]<higher[i]){
                ans++;
            }
        }
        return ans;
        
    }
};