// Problem   : 2095. Minimum Number of Swaps to Make the String Balanced
// Difficulty: Medium
// Tags      : Two Pointers, String, Stack, Greedy, Bracket Sequences
// URL       : https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto c: s){
            if(c=='['){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()=='['){
                    st.pop();
                }
            }
        }
        int n = st.size();
        return (n+1)/2;
    }
};