// Problem   : 2255. Minimum Swaps to Group All 1's Together II
// Difficulty: Medium
// Tags      : Array, Sliding Window
// URL       : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) {
            if (x == 1)
                ones++;
        }
        int curr = 0;
        int maxOnes = 0;
        int l = 0;
        for (int r = 0; r < 2 * n; r++) {
            if (nums[r % n] == 1)
                curr++;
            if (r - l + 1 > ones) {
                if (nums[l % n] == 1)
                    curr--;
                l++;
            }
            maxOnes = max(maxOnes, curr);
        }
        return ones - maxOnes;
    }
};