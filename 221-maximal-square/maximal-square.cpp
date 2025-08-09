class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxSide = 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // First row or first column can only have square of size 1 if '1'
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({ dp[i-1][j], dp[i][j-1], dp[i-1][j-1] }) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        
        return maxSide * maxSide;
    }
};
