// Problem   : 227. Basic Calculator II
// Difficulty: Medium
// Tags      : Math, String, Stack
// URL       : https://leetcode.com/problems/basic-calculator-ii/
// Language  : Cpp
// Date      : 2026-09-11
//

class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        char op = '+';
        stack<long long> st;
        int n = s.size();

        for(int i = 0; i < n; i++){

            if(isdigit(s[i])){
                num = num * 10 + s[i] - '0';
            }

            if((!isdigit(s[i]) && s[i] != ' ') || i == n - 1){

                if(op == '+'){
                    st.push(num);
                }
                else if(op == '-'){
                    st.push(-num);
                }
                else if(op == '*'){
                    long long prev = st.top();
                    st.pop();
                    st.push(prev * num);
                }
                else if(op == '/'){
                    long long prev = st.top();
                    st.pop();
                    st.push(prev / num);
                }

                op = s[i];
                num = 0;
            }
        }

        long long ans = 0;

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};