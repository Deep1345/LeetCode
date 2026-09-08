// Problem   : 1975. Minimum Distance to the Target Element
// Difficulty: Easy
// Tags      : Array
// URL       : https://leetcode.com/problems/minimum-distance-to-the-target-element/
// Language  : Cpp
// Date      : 2026-09-08
//

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans = min(ans,abs(i-start));
            }
        }
        return ans;
    }
};