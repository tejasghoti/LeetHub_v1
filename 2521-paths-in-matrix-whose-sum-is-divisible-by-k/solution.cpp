typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        auto dp = vector(m + 1, vector(n + 1, vector<ll>(k)));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }

                int value = grid[i - 1][j - 1] % k;
                for (int r = 0; r < k; r++) {
                    int prevMod = (r - value + k) % k;
                    dp[i][j][r] =
                        (dp[i - 1][j][prevMod] + dp[i][j - 1][prevMod]) % MOD;
                }
            }
        }

        return dp[m][n][0];
    }
};


/*
const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<vector<long long>>> dp(m, 
            vector<vector<long long>>(n, vector<long long>(k, 0)));
        
        dp[0][0][grid[0][0] % k] = 1;
        
        for (int j = 1; j < n; j++) {
            for (int r = 0; r < k; r++) {
                if (dp[0][j-1][r] > 0) {
                    int new_r = (r + grid[0][j]) % k;
                    dp[0][j][new_r] = (dp[0][j][new_r] + dp[0][j-1][r]) % MOD;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int r = 0; r < k; r++) {
                if (dp[i-1][0][r] > 0) {
                    int new_r = (r + grid[i][0]) % k;
                    dp[i][0][new_r] = (dp[i][0][new_r] + dp[i-1][0][r]) % MOD;
                }
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (dp[i-1][j][r] > 0) {
                        int new_r = (r + grid[i][j]) % k;
                        dp[i][j][new_r] = (dp[i][j][new_r] + dp[i-1][j][r]) % MOD;
                    }
                    if (dp[i][j-1][r] > 0) {
                        int new_r = (r + grid[i][j]) % k;
                        dp[i][j][new_r] = (dp[i][j][new_r] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }
        
        return dp[m-1][n-1][0];
    }
};
*/


