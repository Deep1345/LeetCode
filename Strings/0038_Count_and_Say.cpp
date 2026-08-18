// Problem   : 38. Count and Say
// Difficulty: Medium
// Tags      : String
// URL       : https://leetcode.com/problems/count-and-say/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string say = countAndSay(n-1);
        string ans;
        for(int i=0;i<say.length();i++){
            char ch = say[i];
            int count = 1;
            while(i<say.length() && say[i]==say[i+1]){
                i++;
                count++;
            }
            ans += to_string(count) + ch;
        }
        return ans;
    }
};