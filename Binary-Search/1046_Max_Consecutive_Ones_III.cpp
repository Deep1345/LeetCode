// Problem   : 1046. Max Consecutive Ones III
// Difficulty: Medium
// Tags      : Array, Binary Search, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/max-consecutive-ones-iii/
// Language  : Cpp
// Date      : 2026-09-13
//

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int zeroes = 0;
        int ones = 0;
        for(int r=0;r<n;r++){
            if(nums[r]==1){
                ones = max(ones,r-l+1);
            }
            else{
                zeroes++;
                while(zeroes>k){
                    if(nums[l]==0){
                        zeroes--;
                    }
                    l++;
                }
                ones = max(ones,r-l+1);
            }
        }
        return ones;
    }
};