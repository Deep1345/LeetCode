// Problem   : 2599. Take K of Each Character From Left and Right
// Difficulty: Medium
// Tags      : Hash Table, String, Sliding Window
// URL       : https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = 0;
        int b = 0; 
        int c = 0;
        for(auto ch: s){
            if(ch=='a'){
                a++;
            }
            else if(ch=='b'){
                b++;
            }
            else if(ch=='c'){
                c++;
            }
        }
        if(a<k || b<k || c<k){
            return -1;
        }
        int i = 0;
        int j = 0;
        int maxi = 0;
        while(j<n){
            if(s[j]=='a'){
                a--;
            }
            else if(s[j]=='b'){
                b--;
            }
            else{
                c--;
            }
            while(i<=j && (a<k || b<k || c<k)){
                if(s[i]=='a'){
                    a++;
                }
                else if(s[i]=='b'){
                    b++;
                }
                else{
                    c++;
                }
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return n-maxi;
    }
};