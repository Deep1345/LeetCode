// Problem   : 1756. Minimum Deletions to Make String Balanced
// Difficulty: Medium
// Tags      : String, Dynamic Programming, Stack
// URL       : https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    int minimumDeletions(string s) {
        int del = 0;
        stack<char> st;
        for(char c: s){
            if(st.empty()){
                st.push(c);
            }
            else if(st.top()=='a' && c=='a'){
                st.push(c);
            }
            else if(st.top()=='a' && c=='b'){
                st.push(c);
            }
            else if(st.top()=='b' && c=='b'){
                st.push(c);
            }
            else if(st.top()=='b' && c=='a'){
                del++;
                st.pop();
            }
        }
        return del;
    }
};