// Problem   : 76. Minimum Window Substring
// Difficulty: Hard
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/minimum-window-substring/
// Language  : Cpp
// Date      : 2026-08-14
//

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> hash(256,0);
        if(m>n){
            return "";
        }
        for(auto it: t){
            hash[it]++;
        }
        int cnt = m;
        int start_i = 0;
        int minW = INT_MAX;
        int i = 0;
        int j = 0;
        while(j<n){
            if(hash[s[j]]>0){
                cnt--;
            }
            hash[s[j]]--;
            while(cnt==0){
                int win = j-i+1;
                if(minW>win){
                    minW = win;
                    start_i = i;
                }
                hash[s[i]]++;
                if(hash[s[i]]>0){
                    cnt++;
                }
                i++;
            }
            j++;
        }
        if(minW==INT_MAX){
            return "";
        }
        return s.substr(start_i,minW);
    }
};