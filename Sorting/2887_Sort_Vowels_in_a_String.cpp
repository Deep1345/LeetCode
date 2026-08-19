// Problem   : 2887. Sort Vowels in a String
// Difficulty: Medium
// Tags      : String, Sorting
// URL       : https://leetcode.com/problems/sort-vowels-in-a-string/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    bool isvowel(char c){
        if(c=='A' || c=='E'|| c=='I' || c=='O'|| c=='U' || c=='a'|| c=='e' || c=='i'|| c=='o' || c=='u'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        unordered_map<char,int> mpp;
        int n = s.size();
        for(auto c: s){
            if(isvowel(c)){
                mpp[c]++;
            }
        }
        string temp = "AEIOUaeiou";
        int j = 0;
        for(int i=0;i<n;i++){
            if(isvowel(s[i])==false){
                continue;
            }
            else{
                while(mpp[temp[j]]==0){
                    j++;
                }
                s[i] = temp[j];
                mpp[temp[j]]--;
            }
        }
        return s;
    }
};