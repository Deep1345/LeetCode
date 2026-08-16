// Problem   : 2626. Count the Number of Good Subarrays
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/count-the-number-of-good-subarrays/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int i = 0;
        int j = 0;
        long long ans = 0;
        long long pairs = 0;
        while(j<n){
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;
            while(pairs>=k){
                ans += n - j;
                mpp[nums[i]]--;
                pairs-= mpp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};