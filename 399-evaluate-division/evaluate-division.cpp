class Solution {
public:
    double bfs(unordered_map<string, vector<pair<string, double>>>& adj,
               string start, string end) {
        queue<pair<string, double>> q;
        unordered_set<string> visited;

        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [node, currvalue] = q.front();
            q.pop();

            if (node == end)
                return currvalue;

            for (auto [v, w] : adj[node]) {
                if (!visited.count(v)) {
                    visited.insert(v);
                    q.push({v, currvalue * w});
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_set<string> st;
        for (int i = 0; i < values.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];

            st.insert(u);
            st.insert(v);

            adj[u].push_back({v, w});
            adj[v].push_back({u, 1 / w});
        }
        vector<double> ans;

        for (int i = 0; i < queries.size(); i++) {
            string s = queries[i][0];
            string e = queries[i][1];

            if (st.find(s) == st.end() || st.find(e) == st.end()) {
                ans.push_back(-1.00000);
                continue;
            }

            if (s == e) {
                ans.push_back(1.0);
                continue;
            }

            double ansq = bfs(adj, s, e);

            ans.push_back(ansq);
        }
        return ans;
    }
};