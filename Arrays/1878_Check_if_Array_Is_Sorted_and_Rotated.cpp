// Problem   : 1878. Check if Array Is Sorted and Rotated
// Difficulty: Easy
// Tags      : Array
// URL       : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    bool check(vector<int>& nums) {
        int misMatch = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                misMatch++;
            }
        }
        if(misMatch>1){
            return false;
        }
        return true;
    }
};