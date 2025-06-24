class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            if(nums[i]==key){
                for(int j=i-k;j<=i+k;j++){
                    if(j>=0 && j<n && mp.find(j)==mp.end()){
                        ans.push_back(j);
                        mp[j]++;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};