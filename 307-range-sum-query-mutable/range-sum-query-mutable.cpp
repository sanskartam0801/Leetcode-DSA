class NumArray {
public:
    int n;
    vector<int>seg;

    void build(int node,int left,int right,vector<int>&nums){
        if(left==right){
            seg[node] = nums[left];
            return;
        }
        int mid = left + (right-left)/2;
        build(2*node+1,left,mid,nums);
        build(2*node+2,mid+1,right,nums);
        seg[node] = seg[2*node+1] + seg[2*node+2];
    }

    int query(int node,int left,int right,int l,int r){
        if(left > r || right < l) return 0;
        if(left >= l && right <= r) return seg[node];
        int mid = left + (right-left)/2;
        int lx = query(2*node+1,left,mid,l,r);
        int rx = query(2*node+2,mid+1,right,l,r);

        return lx+rx;
    }

    void updateseg(int node,int left,int right,int index,int val){
        if(left==right){
            seg[node] = val;
            return;
        }
        int mid = left + (right-left)/2;
        if(index <= mid){
            updateseg(2*node+1,left,mid,index,val);
        }
        else{
            updateseg(2*node+2,mid+1,right,index,val);
        }
        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*n,0);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateseg(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */