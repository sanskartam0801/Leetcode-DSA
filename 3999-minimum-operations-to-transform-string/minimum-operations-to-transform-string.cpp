class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        vector<int>freq(26,0);
        for(char c:s) freq[c-'a']++;

        int prev = -1 , last = 0 , ans = 0;
        bool f = false;

        for(int i=1;i<26;i++){
            if(freq[i]>0){
                ans += (prev==-1) ? 0 : (i-prev);
                prev = i;
                last = i;
                f = true;
            }
        }

        return f ? ans + (26-last) : 0;
    }
};