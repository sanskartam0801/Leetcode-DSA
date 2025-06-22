class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minidx = 0,maxidx = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > nums[maxidx]) maxidx = i;
            if(nums[i] < nums[minidx]) minidx = i;
        }
        int mini = min(minidx,maxidx);
        int maxi = max(minidx,maxidx);

        int ans = min({(mini+1+n-maxi),(n-mini),(maxi+1)});
        return ans;
    }
};