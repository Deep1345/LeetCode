// Problem   : 3870. Minimum Moves to Clean the Classroom
// Difficulty: Medium
// Tags      : Array, Hash Table, Bit Manipulation, Breadth-First Search, Matrix
// URL       : https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
// Language  : Cpp
// Date      : 2026-09-01
//

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        // Find S and assign an ID to every L
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if(classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        if(litterCount == 0)
            return 0;

        int fullMask = (1 << litterCount) - 1;

        // best[r][c][mask] = maximum energy seen
        vector<vector<vector<int>>> best(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << litterCount, -1)
            )
        );

        // {row, col, energy, mask}
        queue<array<int, 4>> q;

        q.push({sr, sc, energy, 0});
        best[sr][sc][0] = energy;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        int moves = 0;

        while(!q.empty()) {

            int sz = q.size();

            while(sz--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                if(mask == fullMask)
                    return moves;

                if(e == 0)
                    continue;

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr < 0 || nr >= n ||
                       nc < 0 || nc >= m)
                        continue;

                    if(classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // Collect litter
                    if(classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if(classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Already reached this state with >= energy
                    if(best[nr][nc][newMask] >= newEnergy)
                        continue;

                    best[nr][nc][newMask] = newEnergy;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};