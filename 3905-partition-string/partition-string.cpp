class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.length();
        unordered_map<string,int>mp;

        vector<string>ans;
        string curr = "";

        for(int i=0;i<n;i++){
            curr += s[i];
            if(mp.find(curr) == mp.end()){
                ans.push_back(curr);
                mp[curr]++;
                curr = "";
            }
        }

        return ans;
    }
};