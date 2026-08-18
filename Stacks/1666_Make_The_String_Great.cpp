// Problem   : 1666. Make The String Great
// Difficulty: Easy
// Tags      : String, Stack
// URL       : https://leetcode.com/problems/make-the-string-great/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    string makeGood(string s) {
        string ans;
        for(char c: s){
            if(!ans.empty() && (ans.back()+32==c || ans.back()-32==c)){
                ans.pop_back();
            }
            else{
                ans.push_back(c);
            }
        }
        return ans;
    }
};