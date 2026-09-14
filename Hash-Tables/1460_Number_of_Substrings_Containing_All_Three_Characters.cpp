// Problem   : 1460. Number of Substrings Containing All Three Characters
// Difficulty: Medium
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3,0);
        int n = s.size();
        int l = 0;
        int ans = 0;
        for(int r=0;r<n;r++){
            arr[s[r]-'a']++;
            while(arr[0]>0 && arr[1]>0 && arr[2]>0){
                ans += n-r;
                arr[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};