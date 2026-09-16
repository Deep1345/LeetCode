// Problem   : 35. Search Insert Position
// Difficulty: Easy
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/search-insert-position/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    }
};