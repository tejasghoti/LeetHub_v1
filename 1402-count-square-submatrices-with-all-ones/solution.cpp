class Solution {
public://try solving it again.....
    int countSquares(std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) { // Handle empty matrix case
            return 0;
        }
        int n = matrix[0].size();

        // Create a DP table of the same size as the input matrix
        // dp[i][j] stores the size of the largest square submatrix with all 1s
        // that has its bottom-right corner at matrix[i][j]
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        int totalSquares = 0;

        // Initialize the first row and first column of the dp table
        // and add initial 1x1 squares to totalSquares
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0];
            totalSquares += dp[i][0]; // Add 1x1 squares from the first column
        }

        for (int j = 1; j < n; ++j) { // Start from the second column
            dp[0][j] = matrix[0][j];
            totalSquares += dp[0][j]; // Add 1x1 squares from the first row (excluding the corner already counted)
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    // Calculate dp[i][j] using the recurrence relation
                    dp[i][j] = std::min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    totalSquares += dp[i][j]; // Add the squares ending at (i, j)
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return totalSquares;
    }
};


