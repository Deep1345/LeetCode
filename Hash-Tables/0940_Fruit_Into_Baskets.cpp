// Problem   : 940. Fruit Into Baskets
// Difficulty: Medium
// Tags      : Array, Hash Table, Sliding Window
// URL       : https://leetcode.com/problems/fruit-into-baskets/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp.size()>2){
                mpp[nums[i]]--;
                if(mpp[nums[i]]==0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;

    }
};