// Problem   : 2021. Remove All Occurrences of a Substring
// Difficulty: Medium
// Tags      : String, Stack, Simulation
// URL       : https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    
    bool check(stack<char> st, string part){
        int n = part.size();
        for(int i = n-1; i>=0;i--){
            if(st.top()==part[i]){
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        int m = s.length();
        int n = part.length();
        for(int i=0;i<m;i++){
            st.push(s[i]);
            if(st.size()>=n && check(st,part)==true){
                for(int i=0;i<n;i++){
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};