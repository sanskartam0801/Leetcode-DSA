class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        int n = in.size();
        int ans = 0;
        sort(in.begin(),in.end(),[&](const vector<int>&a,const vector<int>&b){
            return a[1] < b[1];
        });
        int s = in[0][0];
        int e = in[0][1];
        for(int i=1;i<n;i++){
            int curs = in[i][0];
            int cure = in[i][1];
            if(curs < e) ans++;
            else{
                s = curs;
                e = cure;
            }
        }
        return ans;
    }
};