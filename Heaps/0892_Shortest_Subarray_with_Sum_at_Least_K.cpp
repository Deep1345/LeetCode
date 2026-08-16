// Problem   : 892. Shortest Subarray with Sum at Least K
// Difficulty: Hard
// Tags      : Array, Binary Search, Queue, Sliding Window, Heap (Priority Queue), Prefix Sum, Monotonic Queue
// URL       : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<long long> sum(n,0);
        int ans = INT_MAX;
        int j = 0;
        while(j<n){
            if(j==0){
                sum[j] = nums[j];
            }
            else{
                sum[j] = nums[j] + sum[j-1];
            }
            if(sum[j]>=k){
                ans = min(ans,j+1);//i=0
            }
            //check after shrinking window;
            while(!dq.empty() && sum[j]-sum[dq.front()]>=k){
                ans = min(ans,j-dq.front());
                dq.pop_front();
            }
            //maintain increasing order
            while(!dq.empty() && sum[j]<=sum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};