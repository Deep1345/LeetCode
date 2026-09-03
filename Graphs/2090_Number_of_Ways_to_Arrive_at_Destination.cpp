// Problem   : 2090. Number of Ways to Arrive at Destination
// Difficulty: Medium
// Tags      : Dynamic Programming, Graph Theory, Topological Sort, Shortest Path, Dijkstra's Algorithm
// URL       : https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]){
                continue;
            }
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(dis + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};