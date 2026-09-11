// Problem   : 85. Maximal Rectangle
// Difficulty: Hard
// Tags      : Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
// URL       : https://leetcode.com/problems/maximal-rectangle/
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
    int largest(vector<int>& heights) {
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pre(n,vector<int>(m));
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(matrix[i][j] == '1'){
                    sum++;
                }
                else{
                    sum = 0;
                }
                pre[i][j] = sum;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, largest(pre[i]));
        }
        return ans;
    }
};