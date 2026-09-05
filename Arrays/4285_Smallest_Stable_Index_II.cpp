// Problem   : 4285. Smallest Stable Index II
// Difficulty: Medium
// Tags      : Array, Prefix Sum
// URL       : https://leetcode.com/problems/smallest-stable-index-ii/
// Language  : Cpp
// Date      : 2026-09-05
//

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preMax(n);
        vector<int> sufMin(n);
        preMax[0] = nums[0];
        sufMin[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            preMax[i] = max(preMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            sufMin[i] = min(sufMin[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            int score = preMax[i]-sufMin[i];
            if(score<=k){
                return i;
            }
        }
        return -1;
    }
};