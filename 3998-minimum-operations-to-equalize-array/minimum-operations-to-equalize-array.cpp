class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size() , c=0;
        c=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=c) return 1;
        }
        return 0;
    }
};