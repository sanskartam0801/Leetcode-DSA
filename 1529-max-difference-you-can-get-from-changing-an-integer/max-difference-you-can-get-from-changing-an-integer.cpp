class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.length();

        string maxStr = s;
        char toReplaceMax = '\0';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax != '\0') {
            for (char &c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }

        string minStr = s;
        char toReplaceMin = s[0];
        int idx = 0;
        if(toReplaceMin == '1'){
            int i=1;
            while(i<n){
                if(minStr[i]-'0' > 1) {
                    toReplaceMin = minStr[i];
                    idx=i;
                    break;
                }
                i++;
            }
        }
        for (char &c : minStr) {
            if (c == toReplaceMin){
                if(idx == 0) c = '1';
                else c = '0';
            }
        }

        int maxi = stoi(maxStr);
        int mini = stoi(minStr);

        return maxi - mini;
    }
};