#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();

                int g = gcd(a, b);
                if (g > 1) {
                    long long lcm = (1LL * a / g) * b;
                    st.push_back((int)lcm);
                } else {
                    st.push_back(b);
                    st.push_back(a);
                    break;
                }
            }
        }
        return st;
    }
};
