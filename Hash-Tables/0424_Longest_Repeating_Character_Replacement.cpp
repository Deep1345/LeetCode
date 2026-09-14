// Problem   : 424. Longest Repeating Character Replacement
// Difficulty: Medium
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/longest-repeating-character-replacement/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> hash(26,0);
        int l = 0;
        int maxfreq = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            hash[s[r]-'A']++;
            maxfreq = max(maxfreq,hash[s[r]-'A']);
            if(r-l+1-maxfreq>k){
                hash[s[l]-'A']--;
                maxfreq = 0;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};