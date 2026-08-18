// Problem   : 520. Detect Capital
// Difficulty: Easy
// Tags      : String
// URL       : https://leetcode.com/problems/detect-capital/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upper=0;
        for(auto c: word){
            if(isupper(c)){
                upper++;
            }
        }
        if(upper==n){
            return true;
        }
        if(upper==0){
            return true;
        }
        if(upper==1 && isupper(word[0])){
            return true;
        }
        return false;
    }
};