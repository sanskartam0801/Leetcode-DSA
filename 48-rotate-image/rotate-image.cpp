class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // find transpose 
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i < j) swap(matrix[i][j],matrix[j][i]);
            }
        }
        // reverse each row 
        for(int i=0;i<n;i++){
            int a=0,b=n-1;
            while(a<=b) swap(matrix[i][a++],matrix[i][b--]);
        }
    }
};