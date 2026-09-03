// Problem   : 744. Network Delay Time
// Difficulty: Medium
// Tags      : Depth-First Search, Breadth-First Search, Graph Theory, Heap (Priority Queue), Shortest Path, Dijkstra's Algorithm
// URL       : https://leetcode.com/problems/network-delay-time/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n + 1];
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node])
                continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dis + wt < dist[adjNode]){
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxi = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9)
                return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};