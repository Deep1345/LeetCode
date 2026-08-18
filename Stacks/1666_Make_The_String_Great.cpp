// Problem   : 1666. Make The String Great
// Difficulty: Easy
// Tags      : String, Stack
// URL       : https://leetcode.com/problems/make-the-string-great/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c: s){
            if(st.empty()){
                st.push(c);
            }
            else{
                char prev = st.top();
                if(islower(c)){
                    if(c-'a'==prev-'A'){
                        st.pop();
                        continue;
                    }
                }
                else{
                    if(c-'A'==prev-'a'){
                        st.pop();
                        continue;
                    }
                }
                st.push(c);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};