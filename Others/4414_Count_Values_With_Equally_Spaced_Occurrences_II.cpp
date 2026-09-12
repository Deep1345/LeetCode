// Problem   : 4414. Count Values With Equally Spaced Occurrences II
// Difficulty: Medium
// Tags      : N/A
// URL       : https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/
// Language  : Cpp
// Date      : 2026-09-12
//

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>> freq;
        for(int i = 0;i<n;i++){
            freq[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto it: freq){
            int no = it.first;
            vector<int> temp = it.second;
            bool flag = true;
            if(temp.size()<3){
                continue;
            }
            int diff = temp[1]-temp[0];
            int prev = temp[1];
            for(int i=2;i<temp.size();i++){
                if(temp[i]-prev!=diff){
                    flag = false;
                    break;
                }
                else{
                    prev = temp[i];
                    continue;
                }
            }
            if(flag==true){
                ans++;
            }
        }
        return ans;
    }
};