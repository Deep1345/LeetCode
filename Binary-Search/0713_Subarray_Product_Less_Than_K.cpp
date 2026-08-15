// Problem   : 713. Subarray Product Less Than K
// Difficulty: Medium
// Tags      : Array, Binary Search, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/subarray-product-less-than-k/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1){
            return 0;
        }
        int n = nums.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        int product = 1;
        while(r<n){
            product *= nums[r];
            while(product>=k){
                product = product/nums[l];
                l++;
            }
            ans += r-l+1; 
            r++;
        }
        return ans;
    }
};