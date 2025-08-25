class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> result;
        
        // Iterate through all diagonals
        for (int d = 0; d < m + n - 1; d++) {
            vector<int> diagonal;
            
            // Determine starting position for this diagonal
            int row, col;
            if (d < n) {
                row = 0;
                col = d;
            } else {
                row = d - n + 1;
                col = n - 1;
            }
            
            // Collect all elements in this diagonal
            while (row < m && col >= 0) {
                diagonal.push_back(mat[row][col]);
                row++;
                col--;
            }
            
            // If diagonal index is even, reverse the order
            if (d % 2 == 0) {
                reverse(diagonal.begin(), diagonal.end());
            }
            
            // Add diagonal elements to result
            for (int val : diagonal) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};
