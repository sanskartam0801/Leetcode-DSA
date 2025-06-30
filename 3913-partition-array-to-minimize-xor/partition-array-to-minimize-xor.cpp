class Solution {
public:
    int n;
    int dp[250][250]; // Memoization for index and partitions left

    int solve(vector<int>& nums, int idx, int k) {
        if (idx == nums.size() && k == 0) return 0;
        if (idx == nums.size() || k == 0) return INT_MAX;

        if (dp[idx][k] != -1) return dp[idx][k];

        int currXor = 0;
        int res = INT_MAX;

        for (int i = idx; i < nums.size(); ++i) {
            currXor ^= nums[i];
            int next = solve(nums, i + 1, k - 1);
            if (next != INT_MAX) {
                res = min(res, max(currXor, next));
            }
        }

        return dp[idx][k] = res;
    }

    int minXor(vector<int>& nums, int k) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, k);
    }
};
