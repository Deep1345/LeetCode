// Problem   : 1408. Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    int sum(int d, vector<int>& nums){
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans += (nums[i]+d-1)/d;
        }
        return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(sum(mid,nums)<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};