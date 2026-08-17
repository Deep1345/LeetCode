// Problem   : 735. Asteroid Collision
// Difficulty: Medium
// Tags      : Array, Stack, Simulation
// URL       : https://leetcode.com/problems/asteroid-collision/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto x: asteroids){
            if(x>0){
                st.push(x);
                continue;
            }
            while(!st.empty() && st.top()>0 && st.top() < abs(x)){
                st.pop();
            }
            if(st.empty() || st.top()<0){
                st.push(x);
            }
            else if(!st.empty() && st.top()==abs(x)){
                st.pop();
            }
        }
        vector<int> ans(st.size());
        int i = st.size()-1;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};