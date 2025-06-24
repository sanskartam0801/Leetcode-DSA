class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>merged(m+n,0);

        int i=0,j=0,x=0;
        while(i<n && j<m){
            if(nums1[i] <= nums2[j]){
                merged[x++] = nums1[i++];
            }
            else merged[x++] = nums2[j++];
        }
        while(i<n) merged[x++] = nums1[i++];
        while(j<m) merged[x++] = nums2[j++];
        cout<<x<<endl;
        if((m+n)%2==1) return merged[(m+n)/2];
        return (merged[(m+n)/2] + merged[(m+n)/2 - 1])/2.0;
    }
};