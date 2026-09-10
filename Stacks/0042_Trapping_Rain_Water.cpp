// Problem   : 42. Trapping Rain Water
// Difficulty: Hard
// Tags      : Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
// URL       : https://leetcode.com/problems/trapping-rain-water/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int lmax = height[l];
        int rmax = height[r];
        int ans = 0;
        while(l<r){
            if(lmax<rmax){
                l++;
                lmax = max(lmax,height[l]);
                ans += lmax-height[l];
            }
            else{
                r--;
                rmax = max(rmax,height[r]);
                ans += rmax - height[r];
            }
        }
        return ans;
    }
};