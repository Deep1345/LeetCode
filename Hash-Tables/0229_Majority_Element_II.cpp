// Problem   : 229. Majority Element II
// Difficulty: Medium
// Tags      : Array, Hash Table, Sorting, Counting, Boyer–Moore Majority Vote Algorithm
// URL       : https://leetcode.com/problems/majority-element-ii/
// Language  : Cpp
// Date      : 2026-09-05
//

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        int n = nums.size();
        int freq = n/3;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it: mpp){
            int num = it.first;
            int f = it.second;
            if(f>freq){
                ans.push_back(num);
            }
        }
        return ans;
    }
};