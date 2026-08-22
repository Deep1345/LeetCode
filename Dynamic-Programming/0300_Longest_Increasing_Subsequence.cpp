// Problem   : 300. Longest Increasing Subsequence
// Difficulty: Medium
// Tags      : Array, Binary Search, Dynamic Programming, Longest Increasing Subsequence
// URL       : https://leetcode.com/problems/longest-increasing-subsequence/
// Language  : Cpp
// Date      : 2026-08-22
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
    }
};