// Problem   : 1319. Unique Number of Occurrences
// Difficulty: Easy
// Tags      : Array, Hash Table
// URL       : https://leetcode.com/problems/unique-number-of-occurrences/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> hash(1001,0);
        unordered_map<int,int> mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        for(auto it: mpp){
            int freq = it.second;
            if(hash[freq]==0){
                hash[freq]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};