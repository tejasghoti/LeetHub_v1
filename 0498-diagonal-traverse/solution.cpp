/*
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        int diagonals = m + n - 1;
        
        for (int d = 0; d < diagonals; d++) {
            vector<int> diagonal;
            
            int row_start = max(0, d - n + 1);
            int row_end = min(m - 1, d);
            
            for (int row = row_start; row <= row_end; row++) {
                int col = d - row;
                diagonal.push_back(mat[row][col]);
            }
            
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }
            
            for (int val : diagonal) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        int row = 0, col = 0;
        bool up = true;

        while ((int) result.size() < m * n) {
            result.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) {           // hit right border
                    row++;
                    up = false;
                } else if (row == 0) {        // hit top border
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else { // going down
                if (row == m - 1) {           // hit bottom border
                    col++;
                    up = true;
                } else if (col == 0) {         // hit left border
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }

        return result;
    }
};
/*APPROACH: Group by diagonal sum and alternate direction

For each diagonal d (where d = i + j):

1. Even diagonals (0, 2, 4, ...): 
   - Traverse from top-left to bottom-right
   - Row increases: row_start to row_end
   
2. Odd diagonals (1, 3, 5, ...):
   - Traverse from bottom-right to top-left
   - Row decreases: row_end to row_start

3. Row boundaries for diagonal d:
   - row_start = max(0, d - (n-1))
   - row_end = min(m-1, d)
   - col = d - row (derived from i+j=d)

TRACE: mat = [[1,2,3],[4,5,6],[7,8,9]]
m=3, n=3, diagonals=5

d=0 (even):
  row_start = max(0, 0-2) = 0
  row_end = min(2, 0) = 0
  row=0: col=0, value=1
  diagonal=[1]

d=1 (odd):
  row_start = max(0, 1-2) = 0
  row_end = min(2, 1) = 1
  row=1: col=0, value=4
  row=0: col=1, value=2
  diagonal=[4,2]

d=2 (even):
  row_start = max(0, 2-2) = 0
  row_end = min(2, 2) = 2
  row=0: col=2, value=3
  row=1: col=1, value=5
  row=2: col=0, value=7
  diagonal=[3,5,7]

d=3 (odd):
  row_start = max(0, 3-2) = 1
  row_end = min(2, 3) = 2
  row=2: col=1, value=8
  row=1: col=2, value=6
  diagonal=[8,6]

d=4 (even):
  row_start = max(0, 4-2) = 2
  row_end = min(2, 4) = 2
  row=2: col=2, value=9
  diagonal=[9]

result = [1] + [4,2] + [3,5,7] + [8,6] + [9]
       = [1,4,2,3,5,7,8,6,9]

Wait, expected output is [1,2,4,7,5,3,6,8,9]

Let me re-examine: expected is [1,2,4,7,5,3,6,8,9]

Pattern in expected:
[1] [2,4] [7,5,3] [6,8] [9]

That's:
d=0 (even): [1] 
d=1 (odd): [2,4]
d=2 (even): [7,5,3]
d=3 (odd): [6,8]
d=4 (even): [9]

For d=1 (odd), we get [4,2] but need [2,4]
For d=2 (even), we get [3,5,7] but need [7,5,3]
For d=3 (odd), we get [8,6] but need [6,8]

So: reverse even diagonals, keep odd diagonals as-is

Corrected algorithm:

d=1 (odd): traverse forward → [2,4] ✓
d=2 (even): traverse forward then reverse → [7,5,3] ✓
d=3 (odd): traverse forward → [6,8] ✓

Solution: For even d, reverse the diagonal after collecting
*/
