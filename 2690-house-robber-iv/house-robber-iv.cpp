class Solution {
public:
    int n;
    bool isPossible(vector<int>& nums, int k,int mid){
        int house = 0;
        for(int i=0;i<n;i++){
            if(nums[i] <= mid){
                house++;
                i++;
            }
        }
        return house >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int ans = r;

        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(nums,k,mid)){
                r = mid-1;
                ans = mid;
            }
            else l = mid+1;
        }
        return ans;
    }
};