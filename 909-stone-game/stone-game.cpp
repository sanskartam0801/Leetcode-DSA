class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&piles,int i,int j){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int start = piles[i] - solve(piles,i+1,j);
        int end   = piles[j] - solve(piles,i,j-1);

        return dp[i][j] = max(start,end);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,n-1) > 0;
    }
};