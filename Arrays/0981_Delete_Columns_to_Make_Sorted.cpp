// Problem   : 981. Delete Columns to Make Sorted
// Difficulty: Easy
// Tags      : Array, String, Longest Increasing Subsequence
// URL       : https://leetcode.com/problems/delete-columns-to-make-sorted/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int cnt = 0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n-1;i++){
                if(strs[i][j]>strs[i+1][j]){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};