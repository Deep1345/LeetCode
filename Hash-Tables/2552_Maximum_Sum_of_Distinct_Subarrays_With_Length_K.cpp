// Problem   : 2552. Maximum Sum of Distinct Subarrays With Length K
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        unordered_map<int,int> mpp;
        int i = 0;
        for(int j=0;j<n;j++){
            sum = sum+nums[j];
            mpp[nums[j]]++;
            if(j-i+1>k){
                sum = sum - nums[i];
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            if(j-i+1==k && mpp.size()==k){
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};