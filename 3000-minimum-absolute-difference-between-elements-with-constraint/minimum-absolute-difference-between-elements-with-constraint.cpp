class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        if (x == 0) return 0;

        set<int> s;
        int ans = INT_MAX;

        for (int i = x; i < n; ++i) {
            s.insert(nums[i - x]);

            // Find the closest number in set to nums[i]
            auto it = s.lower_bound(nums[i]);
            if (it != s.end()) ans = min(ans, abs(nums[i] - *it));
            if (it != s.begin()) {
                --it;
                ans = min(ans, abs(nums[i] - *it));
            }

            if (ans == 0) return 0; // early exit
        }
        return ans;
    }
};
