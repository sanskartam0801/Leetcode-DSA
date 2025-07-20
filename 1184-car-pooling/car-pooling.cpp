class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        if(n==1) return capacity >= trips[0][0]; 
        vector<int>stops(1001,0);
        for(int i=0;i<n;i++){
            stops[trips[i][1]] += trips[i][0];
            stops[trips[i][2]] -= trips[i][0];
        }
        int curr = 0;
        for(int i=0;i<1001;i++){
            curr += stops[i];
            if(curr>capacity) return false;
        }
        return true;
    }
};