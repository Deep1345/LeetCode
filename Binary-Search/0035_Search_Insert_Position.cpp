// Problem   : 35. Search Insert Position
// Difficulty: Easy
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/search-insert-position/
// Language  : Cpp
// Date      : 2026-08-14
//

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
