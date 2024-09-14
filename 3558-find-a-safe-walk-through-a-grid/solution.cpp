class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> visited(m, vector<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = health - grid[0][0];

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1) return visited[x][y] > 0;

        for (auto& dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int new_health = visited[x][y] - grid[nx][ny];
                if (new_health > visited[nx][ny]) {
                    visited[nx][ny] = new_health;
                    if (new_health > 0) q.push({nx, ny});
                }
            }
        }
    }

    return false;
}
};
