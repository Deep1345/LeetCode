// Problem   : 966. Binary Subarrays With Sum
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/binary-subarrays-with-sum/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = no(nums, goal) - no(nums,goal-1);
        return ans;
    }
    int no(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int l = 0, r = 0, cnt = 0, sum = 0;
        while(r<nums.size()){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
};