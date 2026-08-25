// Problem   : 4080. Smallest Missing Multiple of K
// Difficulty: Easy
// Tags      : Array, Hash Table
// URL       : https://leetcode.com/problems/smallest-missing-multiple-of-k/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> hash(101,0);
        for(auto it: nums){
            if(it%k==0){
                int i = it/k;
                hash[i]++;
            }
        }
        int ans = 0;
        for(int i=1;i<101;i++){
            if(hash[i]==0){
                ans = i*k;
                break;
            }
        }
        if(ans==0){
            return 100+k;
        }
        return ans;
    }
};