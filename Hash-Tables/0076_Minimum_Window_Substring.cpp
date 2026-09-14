// Problem   : 76. Minimum Window Substring
// Difficulty: Hard
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/minimum-window-substring/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> hash(256,0);
        for(auto it: t){
            hash[it]++;
        }
        int l = 0;
        int s_index = 0;
        int len = 1e9;
        int cnt = 0;
        for(int r=0;r<n;r++){
            if(hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;
            while(cnt==m){
                if(r-l+1 < len){
                    len = r-l+1;
                    s_index = l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    cnt--;
                }
                l++;
            }
        }
        if(len == 1e9){
            return "";
        }
        return s.substr(s_index,len);
    }
};