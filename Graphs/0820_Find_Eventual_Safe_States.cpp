// Problem   : 820. Find Eventual Safe States
// Difficulty: Medium
// Tags      : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Kosaraju's Algorithm, Tarjan's SCC Algorithm
// URL       : https://leetcode.com/problems/find-eventual-safe-states/
// Language  : Cpp
// Date      : 2026-09-02
//

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> reverse[graph.size()];
        vector<int> inDegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(auto it: graph[i]){
                reverse[it].push_back(i);
                inDegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeStates;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeStates.push_back(node);
            for(auto adj: reverse[node]){
                inDegree[adj]--;
                if(inDegree[adj]==0){
                    q.push(adj);
                }
            }
        }
        sort(safeStates.begin(),safeStates.end());
        return safeStates;
    }
};