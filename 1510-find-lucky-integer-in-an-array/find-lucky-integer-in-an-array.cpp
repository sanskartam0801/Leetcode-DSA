class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>freq(501,0);
        int n = arr.size();
        for(int i:arr) freq[i]++;
        int ans = 0;
        for(int i=500;i>0;i--){
            if(freq[i]==i){
                ans = i;
                break;
            }
        }
        return ans == 0 ? -1 : ans;
    }
};