// Problem   : 1960. Check if the Sentence Is Pangram
// Difficulty: Easy
// Tags      : Hash Table, String
// URL       : https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n = sentence.size();
        if(n<26){
            return false;
        }
        vector<int> hash(26,0);
        for(auto ch: sentence){
            hash[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(hash[i]==0){
                return false;
            }
        }
        return true;
    }
};