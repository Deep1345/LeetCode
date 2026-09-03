// Problem   : 803. Cheapest Flights Within K Stops
// Difficulty: Medium
// Tags      : Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path
// URL       : https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<pair<int,int>,int>> q;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        q.push({{0,src},0}); // {{dist,node}, steps};
        while(!q.empty()){
            int node = q.front().first.second;
            int steps = q.front().second;
            int dis = q.front().first.first;
            q.pop();
            if(steps>k){
                continue;
            }
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dis+wt<dist[v]){
                    dist[v] = dis+wt;
                    q.push({{dist[v],v},steps+1});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};