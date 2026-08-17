// Problem   : 1128. Remove All Adjacent Duplicates In String
// Difficulty: Easy
// Tags      : String, Stack
// URL       : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(!st.empty() && st.top()==ch){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};