// Problem   : 889. Buddy Strings
// Difficulty: Easy
// Tags      : Hash Table, String
// URL       : https://leetcode.com/problems/buddy-strings/
// Language  : Cpp
// Date      : 2026-08-19
//

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n!=m){
            return false;
        }
        if(s==goal){
            vector<int> hash(26,0);
            for(auto it: s){
                hash[it-'a']++;
                if(hash[it-'a']>1){
                    return true;
                }
            }
            return false;
        }
        vector<int> indices;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                indices.push_back(i);
            }
        }
        if(indices.size()>2){
            return false;
        }
        if(indices.size()<2){
            return false;
        }
        swap(s[indices[0]],s[indices[1]]);
        if(s==goal){
            return true;
        }
        return false;
    }
};