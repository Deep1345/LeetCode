// Problem   : 207. Course Schedule
// Difficulty: Medium
// Tags      : Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Directed Acyclic Graph
// URL       : https://leetcode.com/problems/course-schedule/
// Language  : Cpp
// Date      : 2026-09-02
//

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto it: prerequisites){
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses){
            return true;
        }
        return false;
    }
};