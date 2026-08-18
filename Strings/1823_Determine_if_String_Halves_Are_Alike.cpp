// Problem   : 1823. Determine if String Halves Are Alike
// Difficulty: Easy
// Tags      : String, Counting
// URL       : https://leetcode.com/problems/determine-if-string-halves-are-alike/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    int check(string s, int start, int end){
        int cnt= 0;
        while(start<=end){
            char c = s[start];
            if(c=='a' || c=='e' || c=='o' || c=='i' || c=='u' || c=='A' || c=='E' || c=='U' || c=='I' || c=='O'){
                cnt++;
            }
            start++;
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        if(check(s,0,(n/2)-1) == check(s,n/2,n-1)){
            return true;
        }
        else{
            return false;
        }
    }
};