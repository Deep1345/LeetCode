// Problem   : 150. Evaluate Reverse Polish Notation
// Difficulty: Medium
// Tags      : Array, Math, Stack
// URL       : https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(auto token : tokens) {
            if(token == "+" || token == "-" ||
               token == "*" || token == "/") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(token == "+")
                    st.push(b + a);
                else if(token == "-")
                    st.push(b - a);
                else if(token == "*")
                    st.push(b * a);
                else
                    st.push(b / a);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};