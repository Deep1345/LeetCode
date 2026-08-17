// Problem   : 224. Basic Calculator
// Difficulty: Hard
// Tags      : Math, String, Stack, Recursion
// URL       : https://leetcode.com/problems/basic-calculator/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long long no = 0;
        long long result = 0;
        int sign = 1;
        for (auto c : s) {
            if (isdigit(c)) {
                no = no * 10 + (c - '0');
            }
            else if (c == '+') {
                result += no * sign;
                no = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += no * sign;
                no = 0;
                sign = -1;
            }
            else if (c == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                no = 0;
                sign = 1;
            }
            else if (c == ')') {
                result += no * sign;
                no = 0;
                int stackSign = st.top();
                st.pop();
                int stackResult = st.top();
                st.pop();
                result = stackResult + stackSign * result;
            }
        }
        result += no * sign;
        return result;
    }
};