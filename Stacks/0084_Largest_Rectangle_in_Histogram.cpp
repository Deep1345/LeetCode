// Problem   : 84. Largest Rectangle in Histogram
// Difficulty: Hard
// Tags      : Array, Stack, Monotonic Stack, Range Minimum/Maximum Query
// URL       : https://leetcode.com/problems/largest-rectangle-in-histogram/
// Language  : Cpp
// Date      : 2026-09-11
//

class Solution {
public:
    vector<int> PSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> NSE(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = PSE(heights);
        vector<int> nse = NSE(heights);
        int maxArea = 0;
        for(int i=0;i<heights.size();i++){
            int totalIndices = nse[i] - pse[i] - 1;
            int area = heights[i] * totalIndices;
            maxArea = max(area,maxArea);
        }
        return maxArea;
    }
};