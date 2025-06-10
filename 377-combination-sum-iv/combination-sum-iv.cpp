class Solution {
public:
    int n;
    int dp[1001][201];
    int solve(vector<int>&nums,int target,int idx){
        if(idx>=n || target < 0) return 0;
        if(target==0) return 1;

        if(dp[target][idx]!=-1) return dp[target][idx];

        int take = solve(nums,target-nums[idx],0);
        int notake = solve(nums,target,idx+1);

        return dp[target][idx] = take + notake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);
    }
};