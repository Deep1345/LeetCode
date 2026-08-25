// Problem   : 137. Single Number II
// Difficulty: Medium
// Tags      : Array, Bit Manipulation
// URL       : https://leetcode.com/problems/single-number-ii/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int k=0;k<32;k++){
            int temp = (1<<k);
            int cnt = 0;
            for(auto x: nums){
                if((x&temp)){
                    cnt++;
                }
            }
            if((cnt%3)==1){
                ans |= temp;
            }
        }
        return ans;
    }
};