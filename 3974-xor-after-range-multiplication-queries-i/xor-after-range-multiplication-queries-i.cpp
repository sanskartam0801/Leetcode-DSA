class Solution {
public:
    int mod = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for(auto& q:queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];

            int i = l;
            while(i<=r){
                nums[i] = (1LL*nums[i]*v)%mod;
                i += k;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};