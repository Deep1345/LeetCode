// Problem   : 80. Remove Duplicates from Sorted Array II
// Difficulty: Medium
// Tags      : Array, Two Pointers
// URL       : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int i = 2;
        for(int j = 2; j < n; j++){
            if(nums[j] != nums[i-2]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};