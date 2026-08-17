// Problem   : 983. Validate Stack Sequences
// Difficulty: Medium
// Tags      : Array, Stack, Simulation
// URL       : https://leetcode.com/problems/validate-stack-sequences/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for (int x : pushed) {
            st.push(x);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};