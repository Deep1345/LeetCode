// Problem   : 943. Sum of Subarray Minimums
// Difficulty: Medium
// Tags      : Array, Dynamic Programming, Stack, Monotonic Stack
// URL       : https://leetcode.com/problems/sum-of-subarray-minimums/
// Language  : Cpp
// Date      : 2026-09-10
//

class Solution {
public:
    int mod = 1e9+7;
    vector<int> NSE(vector<int> & arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> PSE(vector<int> & arr){
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = NSE(arr);
        vector<int> psee = PSE(arr);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = (ans + (1LL * arr[i] * (i - psee[i]) * (nse[i] - i)) % mod) % mod;
        }
        return ans;
    }
};