class Solution {
public:
    int mod = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        unordered_map<int, int> freq;

        // Count values on the left of j
        for (int j = 0; j < n; j++) {
            int target = nums[j] * 2;
            left[j] = freq[target];
            freq[nums[j]]++;
        }

        freq.clear();

        // Count values on the right of j
        for (int j = n - 1; j >= 0; j--) {
            int target = nums[j] * 2;
            right[j] = freq[target];
            freq[nums[j]]++;
        }

        // Now compute result
        long long result = 0;
        for (int j = 0; j < n; j++) {
            result = (result + 1LL * left[j] * right[j]) % mod;
        }

        return result;
    }
};
