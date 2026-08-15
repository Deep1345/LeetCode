// Problem   : 3225. Length of Longest Subarray With at Most K Frequency
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            mp[nums[r]]++;
            while (mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};