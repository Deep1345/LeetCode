// Problem   : 2212. Removing Minimum and Maximum From Array
// Difficulty: Medium
// Tags      : Array, Greedy
// URL       : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Language  : Cpp
// Date      : 2026-08-30
//

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_index = -1;
        int max_index = -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                max_index = i;
            }
            if (nums[i] < mini) {
                mini = nums[i];
                min_index = i;
            }
        }
        int left = max(min_index, max_index) + 1;
        int right = n - min(min_index, max_index);
        int both = min(min_index, max_index) + 1 + n - max(min_index, max_index);
        return min({left, right, both});
    }
};