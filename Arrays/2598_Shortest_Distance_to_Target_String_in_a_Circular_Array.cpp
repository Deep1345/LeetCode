// Problem   : 2598. Shortest Distance to Target String in a Circular Array
// Difficulty: Easy
// Tags      : Array, String
// URL       : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Language  : Cpp
// Date      : 2026-09-08
//

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> ind;

        int i = 0;
        for(auto it : words) {
            if(it == target) {
                ind.push_back(i);
            }
            i++;
        }

        int n = ind.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            int diff = abs(ind[i] - startIndex);

            int circularDist = min(diff, (int)words.size() - diff);

            ans = min(ans, circularDist);
        }

        if(ans == INT_MAX) {
            return -1;
        }

        return ans;
    }
};