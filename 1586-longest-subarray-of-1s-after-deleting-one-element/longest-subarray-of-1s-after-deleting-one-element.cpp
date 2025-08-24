class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, prev = 0, curr = 0,zero = 0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
                continue;
            }
            while(i<n && nums[i]==1){
                curr++;
                i++;
            }
            if(zero>=1) ans = max(ans,curr);
            else ans = max(ans,curr+prev);
            prev = curr;
            curr = 0;
            zero = 0;
        }
        if(ans==n) return n-1;
        return ans;
    }
};