// Problem   : 542. 01 Matrix
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Breadth-First Search, Matrix
// URL       : https://leetcode.com/problems/01-matrix/
// Language  : Cpp
// Date      : 2026-09-01
//

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},dist+1});
                    dis[nrow][ncol] = dist+1;
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dis;
    }
};