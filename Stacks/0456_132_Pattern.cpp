// Problem   : 456. 132 Pattern
// Difficulty: Medium
// Tags      : Array, Binary Search, Stack, Monotonic Stack, Ordered Set
// URL       : https://leetcode.com/problems/132-pattern/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        int third = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<third){
                return true;
            }
            while(!st.empty() && st.top()<nums[i]){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};