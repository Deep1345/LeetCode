// Problem   : 966. Binary Subarrays With Sum
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/binary-subarrays-with-sum/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return find(nums,goal) - find(nums,goal-1);
    }
    int find(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int n = nums.size();
        int l = 0;
        int ans = 0;
        int sum = 0;
        for(int r=0;r<n;r++){
            sum += nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }
};