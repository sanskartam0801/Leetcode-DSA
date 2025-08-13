class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;

        for(int i=0;i<n;i++){
            if(i!=nums[i]){
                ans = ans==-1 ? nums[i] : nums[i]&ans;
            }
        }
        return ans==-1 ? 0 : ans;
    }
};