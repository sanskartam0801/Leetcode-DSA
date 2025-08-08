class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        auto check = [&](int t) {
            int ops = 0;
            vector<int> temp = nums;
            for (int i = 0; i + 1 < n; ++i) {
                if (temp[i] != t) {
                    temp[i] *= -1;
                    temp[i+1] *= -1;
                    ++ops;
                }
            }
            return ops <= k && temp[n - 1] == t;
        };
        return check(1) || check(-1);
    }
};
