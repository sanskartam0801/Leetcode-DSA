class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& c) {
        int n = c.size();
        int start_time = 0,time = c[0][0];
        double ans = 0;

        for(int i=0;i<n;i++){
            start_time = c[i][0];
            if(time < c[i][0]){
                ans += (double)c[i][1];
                time = c[i][0] + c[i][1];
            }
            else{
                ans += (double)(c[i][1] + time - start_time);
                time += c[i][1];
            } 
        }
        return ans/n;
    }
};