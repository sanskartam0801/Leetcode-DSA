class Solution {
public:
    string compressedString(string s) {
        int n = s.length();
        string ans = "";
        int i=0;

        while(i<n){
            int count = 1;
            char curr = s[i];
            int j = i+1;

            while(j<n && count<9 && s[j]==curr){
                j++;
                count++;
            }

            ans += (count+'0');
            ans += curr;

            i=j;
        }

        return ans;
    }
};