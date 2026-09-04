// Problem   : 4284. Smallest Stable Index I
// Difficulty: Easy
// Tags      : Array, Prefix Sum
// URL       : https://leetcode.com/problems/smallest-stable-index-i/
// Language  : Cpp
// Date      : 2026-09-04
//

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j=0;j<=i;j++){
                maxi = max(maxi,nums[j]);
            }
            for(int k=i;k<n;k++){
                mini = min(mini,nums[k]);
            }
            int diff = maxi-mini;
            if(diff<=k){
                return i;
            }
        }
        return -1;
    }
};