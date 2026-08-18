// Problem   : 443. String Compression
// Difficulty: Medium
// Tags      : Two Pointers, String
// URL       : https://leetcode.com/problems/string-compression/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 0;
        int i = 0;
        int n = chars.size();
        while(i<n){
            char curr = chars[i];
            int count = 0;
            while(i<n && chars[i]==curr){
                i++;
                count++;
            }
            chars[index] = curr;
            index++;
            if(count>1){
                string count_string = to_string(count);
                for(auto it: count_string){
                    chars[index] = it;
                    index++;
                } 
            }
        }
        return index;
    }
};