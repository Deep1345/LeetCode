// Problem   : 3213. Count Subarrays Where Max Element Appears at Least K Times
// Difficulty: Medium
// Tags      : Array, Sliding Window
// URL       : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        int l = 0;
        long long ans = 0;
        int count = 0;
        for(int r=0;r<n;r++){
            if(nums[r]==maxi){
                count++;
            }
            while(count>=k){
                ans += n-r;
                if(nums[l]==maxi){
                    count--;
                }
                l++;
            }
        }
        return ans;
    }
};