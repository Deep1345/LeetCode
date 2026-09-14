// Problem   : 866. Rectangle Overlap
// Difficulty: Easy
// Tags      : Math, Geometry
// URL       : https://leetcode.com/problems/rectangle-overlap/
// Language  : Cpp
// Date      : 2026-09-14
//

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int xOverlap = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int yOverlap = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        return xOverlap > 0 && yOverlap > 0;
    }
};