class Solution {
public:
    int n;
    bool isValid(vector<int>&nums,int mid,int p){
        int i=0,count=0;

        while(i<n-1){
            if(nums[i+1]-nums[i] <= mid){
                count++;
                i+=2;
            }
            else i++;
            if(count==p) break;
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;

        int l=0,r=nums[n-1]-nums[0];
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isValid(nums,mid,p)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};