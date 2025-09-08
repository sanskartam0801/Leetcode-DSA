class Solution {
public:
    vector<int> nextLargerElement2(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, -1);  // initialize with -1

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
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nums2(2*n,0);
        for(int i=0;i<2*n;i++){
            nums2[i] = nums[i%n];
        }
        vector<int>ans = nextLargerElement2(nums2);
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i] = ans[i];
        }
        return res;
    }
};