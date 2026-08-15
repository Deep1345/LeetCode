// Problem   : 4033. Longest Subsequence With Non-Zero Bitwise XOR
// Difficulty: Medium
// Tags      : Array, Bit Manipulation
// URL       : https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;
        bool flag = false;
        for(auto x: nums){
            xr ^= x;
            if(x!=0){
                flag = true;
            }
        }
        if(xr!=0){
            return n;
        }
        if(flag==true){
            return n-1;
        }
        return 0;
    }
};