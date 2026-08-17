// Problem   : 2470. Removing Stars From a String
// Difficulty: Medium
// Tags      : String, Stack, Simulation
// URL       : https://leetcode.com/problems/removing-stars-from-a-string/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        stack<char> st;
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};