// Problem   : 1354. Find Players With Zero or One Losses
// Difficulty: Medium
// Tags      : Array, Hash Table, Sorting, Counting
// URL       : https://leetcode.com/problems/find-players-with-zero-or-one-losses/
// Language  : Cpp
// Date      : 2026-08-26
//

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> lost_map;
        int n = matches.size();
        for(int i=0;i<n;i++){
            lost_map[matches[i][1]]++;
        }
        vector<vector<int>> ans(2);
        for(int i=0;i<n;i++){
            int won = matches[i][0];
            int lost = matches[i][1];
            if(lost_map.find(won)==lost_map.end()){
                ans[0].push_back(won);
                lost_map[won] = 2;
            }
            if(lost_map[lost]==1){
                ans[1].push_back(lost);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};