class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // Step 1: Build max number by replacing the first non-9 digit with 9
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

        // Step 2: Build min number by replacing the first digit with 0
        string minStr = s;
        char toReplaceMin = s[0];
        for (char &c : minStr) {
            if (c == toReplaceMin) c = '0';
        }

        int maxi = stoi(maxStr);
        int mini = stoi(minStr);

        return maxi - mini;
    }
};
