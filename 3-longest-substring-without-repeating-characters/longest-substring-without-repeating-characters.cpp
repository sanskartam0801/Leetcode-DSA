class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char,int>mp;
        int start = 0;
        int ans = 0;

        for(int e=0;e<n;e++){
            if(mp.find(s[e]) != mp.end()) start = max(start, mp[s[e]] + 1);
            mp[s[e]] = e;
            ans = max(ans,e-start+1);
        }

        return ans;
    }
};