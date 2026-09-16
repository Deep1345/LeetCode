// Problem   : 34. Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ub = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb==ub){
            return {-1,-1};
        }
        return {lb,ub-1};
    }
};