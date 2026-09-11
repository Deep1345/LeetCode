// Problem   : 2800. Minimum String Length After Removing Substrings
// Difficulty: Easy
// Tags      : String, Stack, Simulation
// URL       : https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
// Language  : Cpp
// Date      : 2026-09-11
//

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(auto it: s){
            if(it != 'B' && it != 'D'){
                st.push(it);
            }
            else{
                if(it=='B'){
                    if(st.empty() || st.top()!='A'){
                        st.push(it);
                    }
                    else if(st.top()=='A'){
                        st.pop();
                        continue;
                    }
                }
                else{
                    if(st.empty() || st.top()!='C'){
                        st.push(it);
                    }
                    else if(st.top()=='C'){
                        st.pop();
                        continue;
                    }
                }
            }
        }
        return st.size();
    }
};