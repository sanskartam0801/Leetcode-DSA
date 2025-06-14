class Solution {
public:
    // void dfs(unordered_map<int,vector<pair<int,int>>>&adj,int& ans,int u,vector<bool>&vis){
    //     vis[u] = 1;
        
    //     for(auto& v:adj[u]){
    //         int node = v.first;
    //         int wt = v.second;
    //         ans = min(ans,wt);
    //         if(!vis[node]){
    //             dfs(adj,ans,node,vis);
    //         }
    //     }
    // }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        queue<int>q;
        q.push(1);
        vector<bool>vis(n,false);
        vis[1] = 1;
        int ans = 100001;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = 1;

            for(auto& p : adj[u]){
                int v = p.first;
                int d = p.second;
                ans = min(ans,d);
                if(!vis[v]) q.push(v);
            }
        }
        // dfs(adj,ans,1,vis);
        return ans;
    }
};