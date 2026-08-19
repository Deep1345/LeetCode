// Problem   : 557. Reverse Words in a String III
// Difficulty: Easy
// Tags      : Two Pointers, String
// URL       : https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:  
    string reverseWords(string s) {
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                int j = i;
                while(j<n && s[j]!=' '){
                    j++;
                }
                reverse(s.begin()+i,s.begin()+j);
                i = j;
            }
        }
        return s;
    }
    
};