class Solution {
public:
    typedef long long ll;
    ll solve(int l,int r){
        ll L = 1;
        ll s = 1;
        ll ans = 0;

        while(L<=r){
            ll R = L*4-1;
            ll start = max(L,(ll)l);
            ll end   = min(R,(ll)r);
            
            if(start<=end) ans += (end-start+1)*s;
            s++;
            L = L*4;
        }
        return ans;
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll ans = 0;
        for(auto& q:queries){
            int l = q[0];
            int r = q[1];

            ll steps = solve(l,r);

            ans += (steps+1)/2;
        }

        return ans;
    }
};