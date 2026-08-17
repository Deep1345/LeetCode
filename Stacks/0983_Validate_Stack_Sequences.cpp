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
        int n = pushed.size();
        int i = 0;
        int j = 0;
        stack<int> st;
        while(i<n){
            while(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            st.push(pushed[i]);
            i++;  
        }
        while(!st.empty()){
            if(st.top()==popped[j]){
                st.pop();
                j++;
            }
            else{
                break;
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};