// Problem   : 916. Decoded String at Index
// Difficulty: Medium
// Tags      : String, Stack
// URL       : https://leetcode.com/problems/decoded-string-at-index/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;
        int n = s.size();
        for(auto it: s){
            if(isdigit(it)){
                size *= (it - '0');
            }
            else{
                size++;
            }
        }
        for(int i=n-1;i>=0;i--){
            k = k%size;
            if(k==0 && isalpha(s[i])){
                return string(1,s[i]);
            }
            else{
                if(isalpha(s[i])){
                    size -= 1;
                }
                else{
                    size /= (s[i]-'0');
                }
            }
        }
        return "";
    }
};