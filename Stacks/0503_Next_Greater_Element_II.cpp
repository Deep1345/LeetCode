// Problem   : 503. Next Greater Element II
// Difficulty: Medium
// Tags      : Array, Stack, Monotonic Stack
// URL       : https://leetcode.com/problems/next-greater-element-ii/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                    ans[i] = st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};