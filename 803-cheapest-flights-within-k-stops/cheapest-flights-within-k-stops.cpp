class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto &f : flights){
            int u = f[0], v = f[1], w = f[2];
            adj[u].push_back({v, w});
        }

        // pq stores {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});

        // dist[node][stops] = min cost
        vector<vector<int>> dist(n, vector<int>(k+2, INT_MAX));
        dist[src][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int cost = curr[0], u = curr[1], stops = curr[2];

            if(u == dst) return cost;
            if(stops > k) continue;

            for(auto &p : adj[u]){
                int v = p.first, wt = p.second;
                if(cost + wt < dist[v][stops+1]){
                    dist[v][stops+1] = cost + wt;
                    pq.push({cost + wt, v, stops+1});
                }
            }
        }
        return -1;
    }
};
