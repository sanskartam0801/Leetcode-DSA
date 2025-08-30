class Solution {
public:
    vector<int>parent,rank;
    int find(int& i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void unionbyrank(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu!=pv){
            if(rank[pu] < rank[pv]) parent[pu] = pv;
            else if(rank[pv] < rank[pu]) parent[pv] = pu;
            else{
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];

            int pu = find(u);
            int pv = find(v);

            if(pu==pv) return edges[i];
            unionbyrank(u,v);
        }
        return {};
    }
};