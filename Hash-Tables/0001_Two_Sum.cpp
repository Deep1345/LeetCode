// Problem   : 1. Two Sum
// Difficulty: Easy
// Tags      : Array, Hash Table
// URL       : https://leetcode.com/problems/two-sum/
// Language  : Cpp
// Date      : 2026-08-14
//

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(target - nums[i]))
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};