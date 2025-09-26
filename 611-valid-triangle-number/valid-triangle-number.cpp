class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int count = 0;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];

                    if(a+b > c) count++;
                    else break;
                }
            }
        }

        return count;
    }
};