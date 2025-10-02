class Solution {
public:
    int n;
    void dfs(unordered_map<int,vector<int>>&adj,int element,unordered_set<int>&vis,vector<int>&ans){
        ans.push_back(element);
        vis.insert(element);

        for(auto& v:adj[element]){
            if(vis.find(v)==vis.end()){
                dfs(adj,v,vis,ans);
            }
        }

    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        n = adjacentPairs.size();
        unordered_map<int,vector<int>>adj;
        for(auto vec:adjacentPairs){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans;
        unordered_set<int>vis;

        for(auto it:adj){
            if(it.second.size()==1){
                dfs(adj,it.first,vis,ans);
                break;
            }
        }

        return ans;
    }
};