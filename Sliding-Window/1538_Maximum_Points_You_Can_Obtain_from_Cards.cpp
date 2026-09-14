// Problem   : 1538. Maximum Points You Can Obtain from Cards
// Difficulty: Medium
// Tags      : Array, Sliding Window, Prefix Sum
// URL       : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0;
        int rightSum = 0;
        int n = cardPoints.size();
        for(int i = 0;i<k;i++){
            leftSum += cardPoints[i];
        }
        int maxSum = leftSum+rightSum;
        int l = k-1;
        int r = n-1;
        while(l>-1){
            leftSum -= cardPoints[l];
            rightSum += cardPoints[r];
            maxSum = max(maxSum,leftSum+rightSum);
            l--;
            r--;
        }
        return maxSum;
    }
};