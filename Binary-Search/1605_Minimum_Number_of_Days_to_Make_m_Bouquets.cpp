// Problem   : 1605. Minimum Number of Days to Make m Bouquets
// Difficulty: Medium
// Tags      : Array, Binary Search
// URL       : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Language  : Cpp
// Date      : 2026-09-16
//

class Solution {
public:
    int no(int day,vector<int>& nums,int k){
        int n = nums.size();
        int ans = 0;
        int f = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<=day){
                f++;
                if(f==k){
                    ans++;
                    f = 0;
                }
            }
            else{
                f = 0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(no(mid,bloomDay,k)>=m){
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