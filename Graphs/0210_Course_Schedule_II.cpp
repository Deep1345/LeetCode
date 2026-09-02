// Problem   : 210. Course Schedule II
// Difficulty: Medium
// Tags      : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort
// URL       : https://leetcode.com/problems/course-schedule-ii/
// Language  : Cpp
// Date      : 2026-09-02
//

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for (auto it : prerequisites) {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);
            for (auto neigh : adj[node]) {
                indegree[neigh]--;

                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        if (ans.size() == numCourses)
            return ans;
        return {};
    }
};