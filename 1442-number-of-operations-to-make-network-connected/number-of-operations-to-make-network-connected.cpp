class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int u){
        vis[u] = 1;

        for(auto& v:adj[u]){
            if(!vis[v]) dfs(adj,vis,v);
        }
    }
    int makeConnected(int n, vector<vector<int>>& c) {
        int size = c.size();
        if(n>size+1) return -1;
        int comp = 0;

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<size;i++){
            int u = c[i][0];
            int v = c[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                comp++;
            }
        }
        return comp-1;
    }
};