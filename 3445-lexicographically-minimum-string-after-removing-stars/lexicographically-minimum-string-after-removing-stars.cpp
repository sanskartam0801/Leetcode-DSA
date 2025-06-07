class Solution {
public:
    struct comp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first==b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    string clearStars(string s) {
        int n = s.length();
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    int idx = pq.top().second;
                    s[idx] = '*';
                    pq.pop();
                }
            }
            else pq.push({s[i],i});
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]!='*') ans += s[i];
        }
        return ans;
    }
};