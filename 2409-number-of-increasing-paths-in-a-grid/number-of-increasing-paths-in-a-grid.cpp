class Solution {
public:
    int n,m;
    int dp[1001][1001];
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    int mod = 1e9+7;
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=n || j<0 || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for(int d=0;d<4;d++){
            int newi = i + drow[d];
            int newj = j + dcol[d];
            if(newi>=0 && newi<n && newj>=0 && newj<m && grid[newi][newj] < grid[i][j]){
                ans = (ans + dfs(grid,newi,newj))%mod;
            }
        }
        return dp[i][j] = ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        memset(dp,-1,sizeof(dp));

        int answer = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                answer = (answer + dfs(grid,i,j))%mod;
            }
        }

        return answer;
    }
};