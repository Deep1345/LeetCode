// Problem   : 3743. Reschedule Meetings for Maximum Free Time I
// Difficulty: Medium
// Tags      : Array, Greedy, Sliding Window
// URL       : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/
// Language  : Cpp
// Date      : 2026-08-16
//

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[n-1]);
        int i = 0;
        int j = 0;
        int ans = 0;
        int currSum = 0;
        int m = freeTime.size();
        while(j<m){
            currSum += freeTime[j];
            if(j-i+1>k+1){
                currSum -= freeTime[i];
                i++;
            }
            ans = max(currSum,ans);
            j++;
        }
        return ans;
    }
};