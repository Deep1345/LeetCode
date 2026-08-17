// Problem   : 1552. Build an Array With Stack Operations
// Difficulty: Medium
// Tags      : Array, Stack, Simulation
// URL       : https://leetcode.com/problems/build-an-array-with-stack-operations/
// Language  : Cpp
// Date      : 2026-08-17
//

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 1;
        stack<int> st;
        int j = 0;
        vector<string> ans;
        while(i<=n && j<target.size()){
            if(target[j]==i){
                ans.push_back("Push");
                j++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++; 
        }
        return ans;
    }
};