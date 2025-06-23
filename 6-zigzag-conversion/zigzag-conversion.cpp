class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows==1 || n <= numRows) return s;
        vector<string>store(numRows);
        int d = -1;
        int count = 0;

        int i=0;
        while(i<n){
            store[count] += s[i];
            if(count==(numRows-1) || count==0) d *= -1;
            count += d;
            i++;
        }
        string ans;
        for(auto& x:store) ans += x;
        return ans;
    }
};