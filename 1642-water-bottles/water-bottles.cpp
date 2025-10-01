class Solution {
public:
    int numWaterBottles(int a, int b) {
        int ans = a;

        while(a >= b){
            int x = (a/b);
            ans += x;
            a = a%b + x;
        }

        return ans;
    }
};