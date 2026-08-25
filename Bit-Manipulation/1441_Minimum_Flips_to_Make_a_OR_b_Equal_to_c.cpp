// Problem   : 1441. Minimum Flips to Make a OR b Equal to c
// Difficulty: Medium
// Tags      : Bit Manipulation
// URL       : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
// Language  : Cpp
// Date      : 2026-08-25
//

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while(a!=0 || b!=0 || c!=0){
            if((c&1)==1){
                if((a&1)==0 && (b&1)==0){
                    flips++;
                }
            }
            else{
                if((a&1)==1){
                    flips++;
                }
                if((b&1)==1){
                    flips++;
                }
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flips;
    }
};