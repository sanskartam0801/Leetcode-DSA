class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count=1;
        vector<vector<int>>ans(n,vector<int>(n,0));
        int top=0,bottom=n-1,left=0,right=n-1;
        while(count<n*n+1){
            for(int i=left;i<=right;i++){
                ans[top][i] = count++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans[i][right] = count++;
            }
            right--;
            for(int i=right;i>=left;i--){
                ans[bottom][i] = count++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--){
                ans[i][left] = count++;
            }
            left++;
            if(count==n*n+1) break;
        }
        return ans;
    }
};