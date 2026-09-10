// Problem   : 735. Asteroid Collision
// Difficulty: Medium
// Tags      : Array, Stack, Simulation
// URL       : https://leetcode.com/problems/asteroid-collision/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(auto it: asteroids){
            if(it>0){
                st.push(it);
                continue;
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(it)){
                    st.pop();
                }
                if(st.empty() || st.top()<0){
                    st.push(it);
                }
                else{
                    if(st.top()==abs(it)){
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};