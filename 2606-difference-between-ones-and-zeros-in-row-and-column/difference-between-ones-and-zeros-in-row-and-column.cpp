class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>rowsum;
        vector<int>colsum;

        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++;
                else count--;
            }
            rowsum.push_back(count);
        }
        for(int i=0;i<m;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1) count++;
                else count--;
            }
            colsum.push_back(count);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j] = rowsum[i] + colsum[j];
            }
        }
        return grid;
    }
};