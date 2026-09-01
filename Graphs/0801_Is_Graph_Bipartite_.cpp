// Problem   : 801. Is Graph Bipartite?
// Difficulty: Medium
// Tags      : Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Graph Coloring, Bipartite Graph
// URL       : https://leetcode.com/problems/is-graph-bipartite/
// Language  : Cpp
// Date      : 2026-09-01
//

class Solution {
public:
    bool dfs(int node, int curr_color,vector<vector<int>>& graph, vector<int>& color){
        color[node] = curr_color;
        for(auto neighbor: graph[node]){
            if(color[neighbor]==-1){
                if(dfs(neighbor,!curr_color,graph,color)==false){
                    return false;
                }
                
            }
            else if(color[neighbor]==curr_color){
                    return false;
                }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};