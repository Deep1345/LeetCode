// Problem   : 1753. Path With Minimum Effort
// Difficulty: Medium
// Tags      : Array, Binary Search, Depth-First Search, Breadth-First Search, Union-Find, Heap (Priority Queue), Matrix, Dijkstra's Algorithm
// URL       : https://leetcode.com/problems/path-with-minimum-effort/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>
                        pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r==n-1 && c==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int newr = r + delrow[i];
                int newc = c + delcol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int newEffort = max(diff,abs(heights[r][c]-heights[newr][newc]));
                    if(newEffort<dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};