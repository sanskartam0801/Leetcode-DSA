class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int subs = 0,maxi=INT_MIN,mini = INT_MAX;

        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
            if(maxi-mini > k){
                subs++;
                mini = nums[i];
                maxi = nums[i];
            }
        }
        return subs+1;
    }
};