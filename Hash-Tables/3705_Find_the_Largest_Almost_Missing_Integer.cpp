// Problem   : 3705. Find the Largest Almost Missing Integer
// Difficulty: Easy
// Tags      : Array, Hash Table
// URL       : https://leetcode.com/problems/find-the-largest-almost-missing-integer/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_map<int,int> mpp;
        if(k==n){
            return maxi;
        }
        for(auto x: nums){
            mpp[x]++;
        }
        int prev = -1;
        if(k==1){
            for(int i=0;i<n;i++){
                if(nums[i]>prev && mpp[nums[i]]==1){
                    prev = nums[i];
                }
            }
            return prev;
        }
        if(nums[n-1]>nums[0]){
            if(mpp[nums[n-1]]==1){
                return nums[n-1];
            }
            else if(mpp[nums[0]]==1){
                return nums[0];
            }
        }
        else if(nums[0]>nums[n-1]){
            if(mpp[nums[0]]==1){
                return nums[0];
            }
            else if(mpp[nums[n-1]]==1){
                return nums[n-1];
            }
        }
        return -1;
    }
};