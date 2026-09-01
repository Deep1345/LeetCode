// Problem   : 733. Flood Fill
// Difficulty: Easy
// Tags      : Array, Depth-First Search, Breadth-First Search, Matrix
// URL       : https://leetcode.com/problems/flood-fill/
// Language  : Cpp
// Date      : 2026-09-01
//

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int crr_color = image[sr][sc];
        if(crr_color == color)
            return image;
        image[sr][sc] = color;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = delRow[i] + currRow;
                int ncol = delCol[i] + currCol;
                if(nrow>=0 && nrow<n && ncol<m && ncol >=0 && image[nrow][ncol]==crr_color){
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};