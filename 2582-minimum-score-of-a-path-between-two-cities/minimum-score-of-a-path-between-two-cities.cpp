class Solution {
public:
    void dfs(unordered_map<int,vector<pair<int,int>>>&adj,int& ans,int u,vector<bool>&vis){
        vis[u] = 1;
        
        for(auto& v:adj[u]){
            int node = v.first;
            int wt = v.second;
            ans = min(ans,wt);
            if(!vis[node]){
                dfs(adj,ans,node,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool>vis(n,0);
        int ans = 100001;
        dfs(adj,ans,1,vis);
        return ans;
    }
};