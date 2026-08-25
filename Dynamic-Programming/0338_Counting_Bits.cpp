// Problem   : 338. Counting Bits
// Difficulty: Easy
// Tags      : Dynamic Programming, Bit Manipulation
// URL       : https://leetcode.com/problems/counting-bits/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++){
            if(i%2==1){
                ans[i] = ans[i/2]+1;
            }
            else{
                ans[i] = ans[i/2];
            }
        }
        return ans;
    }
};