// Problem   : 20. Valid Parentheses
// Difficulty: Easy
// Tags      : String, Stack, Bracket Sequences
// URL       : https://leetcode.com/problems/valid-parentheses/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it=='(' || it=='{' || it=='['){
                st.push(it);
            }
            else if(it==')'){
                if(st.empty() || st.top()!='('){                   
                    return false;
                }
                st.pop();
            }
            else if(it==']'){
                if(st.empty() || st.top()!='['){                  
                    return false;
                }
                st.pop();
            }
            else if(it=='}'){
                if(st.empty() || st.top()!='{'){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};