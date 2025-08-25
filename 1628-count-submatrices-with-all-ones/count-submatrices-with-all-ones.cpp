class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> h(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // build histogram
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) h[j] = 0;
                else h[j]++;
            }

            // count submatrices ending at this row
            stack<pair<int,int>> st; // {height, width}
            int sum = 0;
            for (int j = 0; j < m; j++) {
                int cnt = 1;
                while (!st.empty() && st.top().first >= h[j]) {
                    sum -= st.top().first * st.top().second;
                    cnt += st.top().second;
                    st.pop();
                }
                st.push({h[j], cnt});
                sum += h[j] * cnt;
                ans += sum;
            }
        }
        return ans;
    }
};
