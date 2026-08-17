// Problem   : 2846. Robot Collisions
// Difficulty: Hard
// Tags      : Array, Stack, Sorting, Simulation
// URL       : https://leetcode.com/problems/robot-collisions/
// Language  : Cpp
// Date      : 2026-08-18
//

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_index(n);
        for(int i=0;i<n;i++){
            actual_index[i] = i;
        }
        auto lambda = [&](int &i, int &j){
            if(positions[i]<positions[j]){
                return true;
            }
            else{
                return false;
            }
        };
        sort(actual_index.begin(),actual_index.end(),lambda);
        vector<int> ans;
        stack<int> st;
        for(auto currIndex: actual_index){
            if(directions[currIndex]=='R'){
                st.push(currIndex);
            }
            else{
                while(!st.empty() && healths[currIndex]>0){
                    int topIndex = st.top();
                    st.pop();
                    if(healths[topIndex]>healths[currIndex]){
                        healths[topIndex] -= 1;
                        healths[currIndex] = 0;
                        st.push(topIndex);
                    }
                    else if(healths[topIndex]<healths[currIndex]){
                        healths[currIndex] -= 1;
                        healths[topIndex] = 0;
                    }
                    else{
                        healths[currIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};