// Problem   : 1813. Maximum Erasure Value
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/maximum-erasure-value/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int i = 0;
        int j = 0;
        int currSum = 0;
        int ans = 0;
        while(j<n){
            if(st.find(nums[j])==st.end()){
                currSum += nums[j];
                st.insert(nums[j]);
                j++;
                ans = max(ans,currSum);
            }
            else{
                while(st.find(nums[j])!=st.end()){
                    currSum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return ans;
    }
};