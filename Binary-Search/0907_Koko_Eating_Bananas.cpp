// Problem   : 907. Koko Eating Bananas
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/koko-eating-bananas/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    long long solve(int speed,vector<int>& nums){
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += ((long long)nums[i] + speed - 1) / speed;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        int h = *max_element(piles.begin(),piles.end());
        int l = 1;
        int ans = 0;
        while(l<=h){
            int m = (l+h)/2;
            if(solve(m,piles)<=k){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};