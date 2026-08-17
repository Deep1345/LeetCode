// Problem   : 2307. Replace Non-Coprime Numbers in Array
// Difficulty: Hard
// Tags      : Array, Math, Stack, Number Theory, Least Common Multiple, Greatest Common Divisor
// URL       : https://leetcode.com/problems/replace-non-coprime-numbers-in-array/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;
        for(auto x: nums){
            while(!st.empty()){
                int GCD = gcd(x,st.top());
                if(GCD==1){
                    break;
                }
                else{
                    int LCM = x / GCD * st.top();
                    x = LCM;
                    st.pop();
                }
            }
            st.push(x);
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};