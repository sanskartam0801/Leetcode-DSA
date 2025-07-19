class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, long long &sum, vector<vector<bool>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        // Check bounds
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        // If already visited or water (0 or negative), return
        if (vis[i][j] || grid[i][j] <= 0)
            return;

        vis[i][j] = true;
        sum += grid[i][j];

        // Explore 4 directions
        dfs(grid, i + 1, j, sum, vis);
        dfs(grid, i - 1, j, sum, vis);
        dfs(grid, i, j + 1, sum, vis);
        dfs(grid, i, j - 1, sum, vis);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] > 0){
                    long long sum = 0;
                    dfs(grid, i, j, sum, vis);
                    if(sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
