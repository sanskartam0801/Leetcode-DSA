class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int totalProduct = 1;
        for(int num:nums){
            if(num==0) zeroCount++;
            if(num!=0) totalProduct *= num;
        }
        vector<int>ans(n,0);
        if(zeroCount>1) return ans;
        for(int i=0;i<n;i++){
            if(zeroCount==1){
                if(nums[i]==0){
                    ans[i] = totalProduct;
                }
            }
            else{
                ans[i] = totalProduct/nums[i];
            }
        }
        return ans;
    }
};