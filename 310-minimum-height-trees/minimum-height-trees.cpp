class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        unordered_map<int, vector<int>> adj;
        vector<int>indegree(n,0);
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1) q.push(i);
        }

        while(n>2){
            int size = q.size();
            n -= size;

            while(size--){
                int u = q.front();
                q.pop();

                for(auto& v:adj[u]){
                    indegree[v]--;
                    if(indegree[v]==1) q.push(v);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};