class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<pair<int, int>> s; // {value, index}

        for (int i = indexDiff; i < n; ++i) {
            // Insert the element at position i - indexDiff
            s.insert({nums[i - indexDiff], i - indexDiff});

            // Check for value ≥ nums[i] + valueDiff
            auto it = s.lower_bound({nums[i] + valueDiff, -1});
            if (it != s.end()) return {i, it->second};

            // Check for value ≤ nums[i] - valueDiff
            it = s.lower_bound({nums[i] - valueDiff + 1, -1});
            if (it != s.begin()) {
                --it;
                if (abs(nums[i] - it->first) >= valueDiff) {
                    return {i, it->second};
                }
            }
        }

        return {-1, -1};
    }
};
