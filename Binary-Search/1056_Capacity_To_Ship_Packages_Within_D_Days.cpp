// Problem   : 1056. Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    int count(int w,vector<int>& nums){
        int n = nums.size();
        int days = 0;
        long long sum = 0;
        int i = 0;
        while(i<n){
            while(i < n && sum+(1ll*nums[i])<=w){
                sum += nums[i];
                i++;
            }
            days++;
            sum = 0;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = 0;
        for(int i = 0;i<weights.size();i++){
            high += weights[i];
        }
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(count(mid,weights)<=days){
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