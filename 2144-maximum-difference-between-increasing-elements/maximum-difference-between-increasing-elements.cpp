class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxi(n,0);
        maxi[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxi[i] = max(nums[i],maxi[i+1]);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,maxi[i]-nums[i]);
        }
        return ans == 0 ? -1 : ans;
    }
};