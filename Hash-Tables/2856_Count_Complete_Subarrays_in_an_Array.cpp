// Problem   : 2856. Count Complete Subarrays in an Array
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/count-complete-subarrays-in-an-array/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> org;
        for(auto x: nums){
            org[x]++;
        }
        int distinct = org.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()==distinct){
                ans += n-j;
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};