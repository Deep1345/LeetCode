// Problem   : 957. Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// Tags      : String, Stack, Greedy, Bracket Sequences
// URL       : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;
        for(char c : s) {
            if(c == '(') {
                open++;
            }
            else {
                if(open > 0){
                    open--;
                }
                else{
                    ans++;
                }
            }
        }
        return ans + open;
    }
};