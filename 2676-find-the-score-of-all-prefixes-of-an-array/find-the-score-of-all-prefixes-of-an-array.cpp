class Solution {
public:
    typedef long long ll;
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();

        vector<ll>maxi(n,0);
        vector<ll>ans(n,0);

        maxi[0] = nums[0];
        for(int i=1;i<n;i++){
            maxi[i] = max((ll)nums[i],maxi[i-1]);
        }
        for(int i=0;i<n;i++){
            nums[i] = nums[i]+maxi[i];
        }
        ans[0] = nums[0];
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1]+nums[i];
        }
        return ans;
    }
};