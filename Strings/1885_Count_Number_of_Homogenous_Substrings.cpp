// Problem   : 1885. Count Number of Homogenous Substrings
// Difficulty: Medium
// Tags      : Math, String
// URL       : https://leetcode.com/problems/count-number-of-homogenous-substrings/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int n = s.size();
        int ans = 0;
        int len = 1;
        for(int i=0;i<n;i++){
            if(i>0 && s[i]==s[i-1]){
                len++;
            }
            else{
                len = 1;
            }
            ans = (ans+len)%mod;
        }
        return ans;
    }
};