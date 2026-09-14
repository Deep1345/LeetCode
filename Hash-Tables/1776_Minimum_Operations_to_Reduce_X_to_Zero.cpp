// Problem   : 1776. Minimum Operations to Reduce X to Zero
// Difficulty: Medium
// Tags      : Array, Hash Table, Binary Search, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }
        int target = totalSum - x;
        if(target < 0){
            return -1;
        }
        if(target == 0){
            return n;
        }
        int l = 0;
        int sum = 0;
        int maxLen = -1;
        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum > target){
                sum -= nums[l];
                l++;
            }
            if(sum == target){
                maxLen = max(maxLen, r - l + 1);
            }
        }
        if(maxLen == -1){
            return -1;
        }
        return n - maxLen;
    }
};