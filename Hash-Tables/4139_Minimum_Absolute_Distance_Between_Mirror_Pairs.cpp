// Problem   : 4139. Minimum Absolute Distance Between Mirror Pairs
// Difficulty: Medium
// Tags      : Array, Hash Table, Math
// URL       : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    int reverse(int i){
        int ans = 0;
        while(i>0){
            ans = (ans*10) + (i%10);
            i = i/10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(mpp.find(nums[i])!=mpp.end()){
                ans = min(ans,i-mpp[nums[i]]);
            }
            mpp[reverse(nums[i])] = i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};