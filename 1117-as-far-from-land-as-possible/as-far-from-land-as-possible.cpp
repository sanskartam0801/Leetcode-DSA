class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        // Step 1: Add all land cells to the queue
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    q.push({i, j});

        // If there is no land or no water
        if (q.empty() || q.size() == n * n)
            return -1;

        int distance = -1;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        // Step 2: BFS level by level
        while (!q.empty()) {
            int sz = q.size();
            distance++; // Increase distance at each level
            cout<<distance<<endl;

            for (int i = 0; i < sz; ++i) {
                auto [x, y] = q.front(); q.pop();
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // Mark as visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return distance;
    }
};
