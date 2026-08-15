// Problem   : 1034. Subarrays with K Different Integers
// Difficulty: Hard
// Tags      : Array, Hash Table, Sliding Window, Counting
// URL       : https://leetcode.com/problems/subarrays-with-k-different-integers/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int count(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mpp;
        int l = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count(nums,k)-count(nums,k-1);
    }
};