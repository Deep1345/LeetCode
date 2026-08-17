// Problem   : 71. Simplify Path
// Difficulty: Medium
// Tags      : String, Stack
// URL       : https://leetcode.com/problems/simplify-path/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);
        stack<string> st;
        while(getline(ss,token,'/')){
            if(token=="" || token=="."){
                continue;
            }
            if(token != ".."){
                st.push(token);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        if(st.empty()){
            return "/";
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans;
    }
};