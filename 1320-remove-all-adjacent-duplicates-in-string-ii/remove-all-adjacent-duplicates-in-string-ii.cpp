class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        stack<pair<char,int>>st;
        int count = 0;

        for(int i=0;i<n;i++){
            if(st.empty()){
                count=1;
                st.push({s[i],count});
            }
            else{
                if(s[i]==st.top().first){
                    count=st.top().second+1;
                }
                else{
                    count=1;
                }
                st.push({s[i],count});
            }
            if(count==k){
                while(count--) st.pop();  
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};