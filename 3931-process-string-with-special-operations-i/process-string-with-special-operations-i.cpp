class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string ans = "";
        for(char c:s){
            if(c>='a' && c<='z') ans+=c;
            else if(c=='*' && ans.length() > 0) ans.pop_back();
            else if(c=='#') ans += ans;
            else reverse(ans.begin(),ans.end()); 
        }
        return ans;
    }
};