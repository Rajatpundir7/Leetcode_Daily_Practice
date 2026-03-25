class NumArray {
public:
    int n ;
    vector<int> segtree;

    void build(int i ,int l ,int r ,vector<int> &nums){
        int mid = (l + r )/2;
        if(l == r){
            segtree[i] = nums[l];
            return ;
        }
        build(2*i+1 ,l,mid,nums);
        build(2*i+2 ,mid+1 ,r , nums);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
     }

    void updatesegtree(int idx , int val ,int i , int l ,int r  ){
        if(l == r){
            segtree[i] = val;
            return;
        }
        int mid = (l +r) /2;
        if(idx <= mid){
            updatesegtree(idx , val ,2*i +1, l , mid );
        }
        else{
            updatesegtree(idx , val , 2*i +2, mid+1 ,r);
        }

        segtree[i] = segtree[2*i +1 ] + segtree[2*i +2];
    }
    int sumquery(int start , int end ,int i, int l ,int r){
        if(l > end || r < start ){
            return 0;
        }

        if(l >= start && r <= end ){
            return segtree[i];
        }
        int mid = (l +r) /2;
        return sumquery(start , end ,2*i +1 ,l , mid ) + sumquery(start , end , 2*i +2 , mid +1 , r);
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segtree.resize(4*n);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updatesegtree(index , val , 0, 0 , n-1);
    }
    
    int sumRange(int left, int right) {
        return sumquery(left ,right, 0 , 0 , n-1 );
    }
};  

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */