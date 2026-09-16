// Problem   : 162. Find Peak Element
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/find-peak-element/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1]<nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};