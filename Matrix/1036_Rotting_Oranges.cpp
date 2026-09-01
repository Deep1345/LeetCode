// Problem   : 1036. Rotting Oranges
// Difficulty: Medium
// Tags      : Array, Breadth-First Search, Matrix
// URL       : https://leetcode.com/problems/rotting-oranges/
// Language  : Cpp
// Date      : 2026-09-01
//

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int Freshcnt = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j]==1){
                    Freshcnt++;
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        int timer = 0;
        int cnt = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            timer = max(t,timer);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 1;
                    cnt++;
                }
            }
        }
        if(cnt==Freshcnt){
            return timer;
        }
        return -1;
    }
};