// Problem   : 935. Orderly Queue
// Difficulty: Hard
// Tags      : Math, String, Sorting, Lexicographically Minimal String Rotation
// URL       : https://leetcode.com/problems/orderly-queue/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans = s;
        int n = s.size();
        for(int i=1;i<=n-1;i++){
            string temp = s.substr(i,n) + s.substr(0,i);
            ans = min(ans,temp);
        }
        return ans;
    }
};