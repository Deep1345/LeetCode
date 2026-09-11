// Problem   : 239. Sliding Window Maximum
// Difficulty: Hard
// Tags      : Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue, Range Minimum/Maximum Query
// URL       : https://leetcode.com/problems/sliding-window-maximum/
// Language  : Cpp
// Date      : 2026-09-11
//

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};