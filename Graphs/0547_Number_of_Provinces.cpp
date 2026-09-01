// Problem   : 547. Number of Provinces
// Difficulty: Medium
// Tags      : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory
// URL       : https://leetcode.com/problems/number-of-provinces/
// Language  : Cpp
// Date      : 2026-09-01
//

class Solution {
private:
    void bfs(int node, vector<int>& vis, vector<vector<int>>& isConnected){
        queue<int> q;
        vis[node] = 1;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int j = 0; j < isConnected[curr].size(); j++){
                if(isConnected[curr][j] == 1 && vis[j] == 0){
                    vis[j] = 1;
                    q.push(j);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int components = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bfs(i,vis,isConnected);
                components++;
            }
        }
        return components;
    }
};