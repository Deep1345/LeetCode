// Problem   : 402. Remove K Digits
// Difficulty: Medium
// Tags      : String, Stack, Greedy, Monotonic Stack
// URL       : https://leetcode.com/problems/remove-k-digits/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char it : num){
            while(!st.empty() && k > 0 && st.top() > it){
                st.pop();
                k--;
            }
            st.push(it);
        }
        while(k > 0){
            st.pop();
            k--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while(i < ans.size() && ans[i] == '0'){
            i++;
        }
        if(i == ans.size()){
            return "0";
        }
        return ans.substr(i);
    }
};