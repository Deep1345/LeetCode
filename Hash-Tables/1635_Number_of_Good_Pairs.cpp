// Problem   : 1635. Number of Good Pairs
// Difficulty: Easy
// Tags      : Array, Hash Table, Math, Counting
// URL       : https://leetcode.com/problems/number-of-good-pairs/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans = 0;
        for(auto it: nums){
            if(mpp.find(it)==mpp.end()){
                mpp[it]++;
            }
            else{
                ans += mpp[it];
                mpp[it]++;
            }
        }
        return ans;
    }
};