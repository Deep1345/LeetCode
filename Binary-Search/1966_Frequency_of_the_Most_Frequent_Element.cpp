// Problem   : 1966. Frequency of the Most Frequent Element
// Difficulty: Medium
// Tags      : Array, Binary Search, Greedy, Sliding Window, Sorting, Prefix Sum
// URL       : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        long sum = 0;
        while(r<n){
            sum += nums[r];
            long target = nums[r];
            if((r-l+1)*target-sum>k){
                sum -= nums[l];
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};