class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();

        // ----- 1. subsequence of length 1 -----
        if (m == 1) {
            long long best = LLONG_MIN;
            for (int x : nums) best = max(best, 1LL * x * x);
            return best;
        }

        // ----- 2. general case m >= 2 -----
        long long prefixMax = nums[0];
        long long prefixMin = nums[0];
        long long ans       = LLONG_MIN;

        for (int j = m - 1; j < n; ++j) {
            // best product that ends at j
            long long prod1 = 1LL * nums[j] * prefixMax;
            long long prod2 = 1LL * nums[j] * prefixMin;
            ans = max(ans, max(prod1, prod2));

            // grow the prefix so next j has one more allowed i
            if (j - m + 2 < n) {
                long long val = nums[j - m + 2];
                prefixMax = max(prefixMax, val);
                prefixMin = min(prefixMin, val);
            }
        }
        return ans;
    }
};
