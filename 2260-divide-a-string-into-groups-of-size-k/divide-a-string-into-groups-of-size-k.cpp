class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.length();
        vector<string>ans;
        int i=0;

        while(i<n){
            if(i+k>=n) break;
            string temp = s.substr(i,k);
            ans.push_back(temp);
            i=i+k;
        }
        if(i<n){
            string temp = "";
            while(i<n){
                temp += s[i];
                i++;
                k--;
            }
            while(k){
                temp += fill;
                k--;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};