class Solution {
public:
    vector<int> sumZero(int n) {
        int rem = n;
        int x = 1;
        vector<int>ans(n,0);
        int i=0;
        while(i<n){
            if(i==n-1 && n%2==1){
                ans[i] = 0;
                i++;
                continue;
            }
            ans[i] = x;
            ans[i+1] = -x;
            x++;
            i+=2;
        }
        return ans;
    }
};