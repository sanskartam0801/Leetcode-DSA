class Solution {
public:
    int bs(vector<vector<int>>& items,int target){
        int l = 0 , r = items.size()-1;
        int ans = 0;
        while(l<=r){
            int mid = l+ (r-l)/2;
            if(items[mid][0] <= target){
                ans =items[mid][1];
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        int n = q.size();
        vector<int>ans;
        sort(items.begin(),items.end());

        for(int i=1;i<items.size();i++){
            items[i][1] = max(items[i][1],items[i-1][1]);
        }

        for(int i=0;i<n;i++){
            int x = bs(items,q[i]);
            ans.push_back(x);
        }

        return ans;
    }
};