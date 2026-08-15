// Problem   : 1321. Get Equal Substrings Within Budget
// Difficulty: Medium
// Tags      : String, Binary Search, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/get-equal-substrings-within-budget/
// Language  : Cpp
// Date      : 2026-08-15
//

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        int cost = 0;
        for(int r = 0; r<n; r++){
            cost += abs(s[r]-t[r]);
            while(cost>maxCost){
                cost -= abs(s[l]-t[l]);
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};