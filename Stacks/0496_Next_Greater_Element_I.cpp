// Problem   : 496. Next Greater Element I
// Difficulty: Easy
// Tags      : Array, Hash Table, Stack, Monotonic Stack
// URL       : https://leetcode.com/problems/next-greater-element-i/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        /////////////<val,NGE>
        stack<int> st;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mpp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else if(st.top()>nums2[i]){
                mpp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }
        int m = nums1.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};