class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, sum = 0;
        unordered_set<int> seen;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            sum += nums[right];
            ans = max(ans, sum);
        }
        return ans;
    }
};
