#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    // Check all four directions
                    for (int d = 0; d < 4; d++) {
                        int nr = i + dirs[d][0];
                        int nc = j + dirs[d][1];

                        // When out of bounds or water, increment perimeter edge
                        if (nr < 0 || nr >= r || nc < 0 || nc >= c || grid[nr][nc] == 0) {
                            perimeter++;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};

