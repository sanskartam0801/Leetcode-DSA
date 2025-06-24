class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l = left.size();
        int r = right.size();
        
        int leftmax = INT_MIN,rightmax = INT_MIN;

        for(int& i:left) leftmax = max(leftmax,i-0);
        for(int& i:right) rightmax = max(rightmax,n-i);

        return max(leftmax,rightmax);
    }
};