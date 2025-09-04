class Graph {
public:
    unordered_map<int,vector<pair<int,int>>>adj;
    int size;
    Graph(int n, vector<vector<int>>& edges) {
        size = n;
        for(auto e:edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
        }
    }
    
    void addEdge(vector<int> e) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v,w});
        size++;
    }
    
    int shortestPath(int node1, int node2) {
        vector<bool>vis(size,0);
        vector<int>dist(size,INT_MAX);
        queue<pair<int,int>>q;
        q.push({0,node1});
        vis[node1] = 1;
        dist[node1] = 0;

        while(!q.empty()){
            int u = q.front().second;
            q.pop();

            for(auto p:adj[u]){
                int v = p.first;
                int w = p.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u]+w;
                    q.push({dist[v],v});
                }
            }
        }
        return dist[node2]==INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */