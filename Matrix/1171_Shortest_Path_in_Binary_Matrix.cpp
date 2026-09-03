// Problem   : 1171. Shortest Path in Binary Matrix
// Difficulty: Medium
// Tags      : Array, Breadth-First Search, Matrix
// URL       : https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] || grid[n-1][m-1]){
            return -1;
        }
        if(n==1 && m==1){
            return 1;
        }
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}}); // {noOfNodesVisited,{i,j}};
        int delRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int delCol[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            int node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && grid[nRow][nCol]==0){
                    if(1+node<dist[nRow][nCol]){
                        dist[nRow][nCol] = 1+node;
                        q.push({1+node,{nRow,nCol}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e9){
            return -1;
        }
        return dist[n-1][m-1];
    }
};