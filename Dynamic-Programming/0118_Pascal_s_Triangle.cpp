// Problem   : 118. Pascal's Triangle
// Difficulty: Easy
// Tags      : Array, Dynamic Programming
// URL       : https://leetcode.com/problems/pascals-triangle/
// Language  : Cpp
// Date      : 2026-09-06
//

class Solution {
public:
////
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};