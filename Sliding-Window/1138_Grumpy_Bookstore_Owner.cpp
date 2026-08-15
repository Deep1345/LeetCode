// Problem   : 1138. Grumpy Bookstore Owner
// Difficulty: Medium
// Tags      : Array, Sliding Window
// URL       : https://leetcode.com/problems/grumpy-bookstore-owner/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int l = 0;
        int sum = 0;
        int grumpy_sum = 0;
        for(int r = 0; r<n; r++){
            if(grumpy[r]==1){
                sum += customers[r];
            }
            if(r-l+1>minutes){
                if(grumpy[l]==1){
                    sum-=customers[l];
                }
                l++;
            }
            grumpy_sum = max(sum,grumpy_sum);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                ans += customers[i];
            }
        }
        ans += grumpy_sum;
        return ans;
    }
};