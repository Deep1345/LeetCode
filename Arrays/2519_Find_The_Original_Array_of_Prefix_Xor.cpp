// Problem   : 2519. Find The Original Array of Prefix Xor
// Difficulty: Medium
// Tags      : Array, Bit Manipulation
// URL       : https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans(n,0);
        ans[0] = pref[0];
        for(int i=1;i<n;i++){
            if(pref[i]==0){
                ans[i] = pref[i-1];
                continue;
            }
            ans[i] = pref[i-1] ^ pref[i];
        }
        return ans;
    }
};