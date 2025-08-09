class Solution {
public:
    int n;
    int dp[305][305]; // dp[left][right]

    int solve(vector<int>& nums, int left, int right) {
        if (left + 1 == right) return 0; // no balloons to burst

        if (dp[left][right] != -1) return dp[left][right];

        int ans = 0;
        for (int i = left + 1; i < right; i++) {
            int coins = nums[left] * nums[i] * nums[right]
                        + solve(nums, left, i)
                        + solve(nums, i, right);
            ans = max(ans, coins);
        }
        return dp[left][right] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, n - 1);
    }
};
