class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.length();
        int ans = 0,i=0,x=0;

        while(i<n-1){
            if(dir[i]=='R' && dir[i+1]=='L'){
                ans += 2;
                dir[i] = 'S';
                dir[i+1] = 'S';
            }
            else if(dir[i]=='R' && dir[i+1]=='S'){
                ans += 1;
                dir[i] = 'S';
            }
            else if(dir[i]=='S' && dir[i+1]=='L'){
                ans += 1; 
                dir[i+1] = 'S';
            }
            if(dir[i]=='R') x++;
            else{
                ans += x;
                x=0;
            }
            i++;
        }
        return ans;
    }
};