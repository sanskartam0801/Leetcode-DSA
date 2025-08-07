class Solution {
public:
    int maxBalancedShipments(vector<int>& w) {
        int n = w.size();
        int ans = 0, curmaxi = 0,s=0;

        for(int e=0;e<n;e++){
            if(w[e] < curmaxi){
                ans++;
                curmaxi = 0;
                s = e+1;
            }
            else curmaxi = max(curmaxi,w[e]);
        }
        return ans;
    }
};