// Problem   : 2394. Count Subarrays With Score Less Than K
// Difficulty: Hard
// Tags      : Array, Binary Search, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        int i = 0;
        int j = 0;
        long long sum = 0;
        while(j<n){
            sum += nums[j];
            while(i<=j && sum * (j-i+1)>=k){
                sum -= nums[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
};