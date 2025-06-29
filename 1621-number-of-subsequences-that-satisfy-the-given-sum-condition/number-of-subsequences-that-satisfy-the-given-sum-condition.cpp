class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        // Precompute powers of 2
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
            power[i] = (power[i - 1] * 2) % mod;
        
        int i = 0, j = n - 1;
        int ans = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                ans = (ans + power[j - i]) % mod;
                i++;
            } else {
                j--;
            }
        }

        return ans;
    }
};
