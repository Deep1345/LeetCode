// Problem   : 451. Sort Characters By Frequency
// Difficulty: Medium
// Tags      : Hash Table, String, Sorting, Heap (Priority Queue), Bucket Sort, Counting
// URL       : https://leetcode.com/problems/sort-characters-by-frequency/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    static auto compare(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        for(auto c: s){
            mpp[c]++;
        }
        vector<pair<char,int>> freq;
        for(auto p: mpp){
            freq.push_back({p.first,p.second});
        }
        sort(freq.begin(),freq.end(),compare);
        string ans;
        for(auto &p : freq) {
            for(int i=0;i<p.second;i++){
                ans += p.first;
            }
        }
        return ans;
        
    }
};