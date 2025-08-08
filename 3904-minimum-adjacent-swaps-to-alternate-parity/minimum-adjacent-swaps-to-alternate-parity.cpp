class Solution {
public:
    int helper(vector<int> v){
        int c=0;
        for(int i=0;i<v.size();i++){
            c += abs(v[i]-2*i);
        }

        return c;
    }
    
    int minSwaps(vector<int>& v){
        vector<int> even, odd;
        for(int i=0;i<v.size(); ++i){
            if(v[i]%2==0) even.push_back(i);
            else odd.push_back(i);
        }
    
        int n=v.size();
        int c1=even.size();
        int c2=odd.size();
    
        if(abs(c1-c2)>1) return -1;
    
        int ans=INT_MAX;

        if(c1>=c2) ans=min(ans, helper(even));
        if(c2>=c1) ans=min(ans,helper(odd));

        return ans;
    }
};