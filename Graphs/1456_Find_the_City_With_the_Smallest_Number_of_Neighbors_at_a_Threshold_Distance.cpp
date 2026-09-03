// Problem   : 1456. Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Difficulty: Medium
// Tags      : Dynamic Programming, Graph Theory, Shortest Path, Dijkstra's Algorithm, Bellman–Ford Algorithm, Floyd–Warshall Algorithm
// URL       : https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// Language  : Cpp
// Date      : 2026-09-03
//

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int> (n,1e9));
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        for(int i=0;i<n;i++){
            mat[i][i] = 0;
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]!=1e9 && mat[via][j]!=1e9){
                        mat[i][j] = min(mat[i][j],mat[i][via]+mat[via][j]);
                    }
                }
            }
        }
        int ans = 0;
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mini){
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};