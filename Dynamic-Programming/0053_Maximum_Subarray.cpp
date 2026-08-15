// Problem   : 53. Maximum Subarray
// Difficulty: Medium
// Tags      : Array, Divide and Conquer, Dynamic Programming
// URL       : https://leetcode.com/problems/maximum-subarray/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum = sum + nums[i];
            maxi = max(sum,maxi);
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};