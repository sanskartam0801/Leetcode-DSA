class Solution {
public:
    int n,m,zero,sx,sy,ex,ey;
    int dx[4] = {0,-1,0,+1};
    int dy[4] = {-1,0,+1,0};
    int solve(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis,int remain){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==-1) return 0;
        if(i==ex && j==ey) return remain==0;

        vis[i][j] = 1;

        int ans = 0;

        for(int d=0;d<4;d++){
            int newx = i + dx[d];
            int newy = j + dy[d];

            ans += solve(grid,newx,newy,vis,remain-1);
        }

        vis[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        zero = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) zero++;
                else if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==2){
                    ex=i;
                    ey=j;
                }
            }
        }
        vector<vector<bool>>vis(m,vector<bool>(n,0));

        return solve(grid,sx,sy,vis,zero+1);
    }
};