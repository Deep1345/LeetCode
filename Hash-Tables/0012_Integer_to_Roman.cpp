// Problem   : 12. Integer to Roman
// Difficulty: Medium
// Tags      : Hash Table, Math, String
// URL       : https://leetcode.com/problems/integer-to-roman/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    vector<int> val{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string intToRoman(int num) {
        string ans;
        for(int i=0;i<13;i++){
            if(num==0){
                break;
            }
            int times = num/val[i];
            while(times){
                ans += sym[i];
                times--;
            }
            num = num%val[i];
        }
        return ans;
    }
};