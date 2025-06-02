class Solution {
public:
    int n1, n2, n3;
    vector<vector<vector<int>>> dp;

    bool solve(string &s1, string &s2, string &s3, int idx1, int idx2, int idx3) {
        if (idx3 == n3) {
            return idx1 == n1 && idx2 == n2;
        }

        if (dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];

        bool one = false, two = false;

        if (idx1 < n1 && s1[idx1] == s3[idx3]) {
            one = solve(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
        }

        if (idx2 < n2 && s2[idx2] == s3[idx3]) {
            two = solve(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
        }

        return dp[idx1][idx2][idx3] = one || two;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length();
        n2 = s2.length();
        n3 = s3.length();

        if (n1 + n2 != n3) return false;

        dp = vector<vector<vector<int>>>(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));

        return solve(s1, s2, s3, 0, 0, 0);
    }
};