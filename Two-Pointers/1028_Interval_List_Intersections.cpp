// Problem   : 1028. Interval List Intersections
// Difficulty: Medium
// Tags      : Array, Two Pointers, Sweep Line
// URL       : https://leetcode.com/problems/interval-list-intersections/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;
        if(n==0 || m==0){
            return ans;
        }
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];
            if(end1<start2){
                i++;
                continue;
            }
            else if(end2<start1){
                j++;
                continue;
            }
            else if(start1<=start2){
                int minEnd = min(end1,end2);
                ans.push_back({start2,minEnd});
                if(end1<end2){
                    i++;
                }
                else if(end2<end1){
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
            else if(start2<=start1){
                int minEnd = min(end1,end2);
                ans.push_back({start1,minEnd});
                if(end1<end2){
                    i++;
                }
                else if(end2<end1){
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};