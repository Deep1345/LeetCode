// Problem   : 11. Container With Most Water
// Difficulty: Medium
// Tags      : Array, Two Pointers, Greedy
// URL       : https://leetcode.com/problems/container-with-most-water/
// Language  : Cpp
// Date      : 2026-08-14
//

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int maxArea = 0;
        while(l<r){
            int area = min(height[l],height[r]) * (r-l);
            maxArea = max(area,maxArea);
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxArea;
    }
};