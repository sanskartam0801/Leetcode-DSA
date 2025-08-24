class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k!=0) return false;

        unordered_map<int,int>mp;
        for(int& i:nums) mp[i]++;
        for(auto& it:mp){
            if(it.second > (n/k)) return false;
        }
        return true;

    }
};