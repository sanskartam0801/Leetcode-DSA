class Solution {
public:
    const int MOD = 1e9 + 7;
    const int BASE = 113;

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int low = 0, high = min(nums1.size(), nums2.size());
        int res = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (hasCommonSubarray(nums1, nums2, mid)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return res;
    }

    bool hasCommonSubarray(vector<int>& A, vector<int>& B, int len) {
        if (len == 0) return true;

        long long hash = 0;
        long long power = 1;
        unordered_set<long long> hashes;

        for (int i = 0; i < len; ++i)
            power = (power * BASE) % MOD;

        // Hash all substrings of A of length len
        hash = 0;
        for (int i = 0; i < A.size(); ++i) {
            hash = (hash * BASE + A[i]) % MOD;
            if (i >= len - 1) {
                if (i >= len) {
                    hash = (hash - (A[i - len] * power) % MOD + MOD) % MOD;
                }
                hashes.insert(hash);
            }
        }

        // Now look for a match in B
        hash = 0;
        for (int i = 0; i < B.size(); ++i) {
            hash = (hash * BASE + B[i]) % MOD;
            if (i >= len - 1) {
                if (i >= len) {
                    hash = (hash - (B[i - len] * power) % MOD + MOD) % MOD;
                }
                if (hashes.count(hash)) return true;
            }
        }

        return false;
    }
};
