class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>freq(26,0);
        int n = s.length();
        for(char c:s) freq[c-'a']++;
        for(char c:t){
            if(freq[c-'a'] > 0) freq[c-'a']--;
        } 
        int ans = 0;
        for(int i=0;i<26;i++){
            ans += freq[i];
        }
        return ans;
    }
};