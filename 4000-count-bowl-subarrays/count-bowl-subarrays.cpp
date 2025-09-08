class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, -1);

        st.push(arr[n-1]);

        for(int i = n-2; i >= 0; i--) {
            while(!st.empty() && arr[i] >= st.top()) {
                st.pop();
            }
            if(!st.empty()) {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int>prev = nextLargerElement(nums);
        reverse(nums.begin(),nums.end());
        vector<int>next = nextLargerElement(nums);
        reverse(next.begin(),next.end());

        for(int i=0;i<n;i++){
            if(prev[i]!=-1 && next[i]!=-1) ans++;
        }
        return ans;
    }
};