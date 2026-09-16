// Problem   : 540. Single Element in a Sorted Array
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/single-element-in-a-sorted-array/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n-2;
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            else if((mid%2==0 && nums[mid]==nums[mid+1])||(mid%2==1 && nums[mid]==nums[mid-1])){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return nums[high];
    }
};