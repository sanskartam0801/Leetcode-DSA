class Solution {
public:
    int mod = 1e9 + 7;

    void build(int node, int left, int right, vector<long long>& seg, vector<int>& ans) {
        if (left == right) {
            seg[node] = ans[left] % mod;
            return;
        }
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid, seg, ans);
        build(2 * node + 2, mid + 1, right, seg, ans);
        seg[node] = (seg[2 * node + 1] * seg[2 * node + 2]) % mod;
    }

    long long query(int node, int left, int right, int l, int r, vector<long long>& seg) {
        if (left > r || right < l) return 1;  // Neutral element for multiplication
        if (left >= l && right <= r) return seg[node];

        int mid = (left + right) / 2;
        long long leftProd = query(2 * node + 1, left, mid, l, r, seg);
        long long rightProd = query(2 * node + 2, mid + 1, right, l, r, seg);

        return (leftProd * rightProd) % mod;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        for (int i = 30; i >= 0; i--) {
            int x = (1 << i);
            if (n >= x) {
                n -= x;
                ans.push_back(x);
            }
            if (n == 0) break;
        }
        reverse(ans.begin(), ans.end());

        int size = ans.size();
        vector<long long> seg(4 * size, 1);
        build(0, 0, size - 1, seg, ans);

        vector<int> res;
        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            long long prod = query(0, 0, size - 1, l, r, seg);
            res.push_back((int)prod);
        }
        return res;
    }
};
