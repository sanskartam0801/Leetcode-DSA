class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();

        int ans = 0;
        
        for(int i=0;i<n-m;++i){
            int x = 0;
            while(x<m){
                if(pattern[x]==1){
                    if(nums[x+i] >= nums[x+i+1]) break;
                    else x++;
                }
                else if(pattern[x]==0){
                    if(nums[x+i] != nums[x+i+1]) break;
                    else x++;
                }
                else if(pattern[x]==-1){
                    if(nums[x+i] <= nums[x+i+1]) break;
                    else x++;
                }
            }
            if(x==m) ans++;
        }
        return ans;
    }
};