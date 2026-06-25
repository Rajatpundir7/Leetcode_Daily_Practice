class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        
        vector<int>diff(n,0);
        for(int i = 0;i < m;i++){
            int left = queries[i][0];
            int right = queries[i][1];
            diff[left] += 1;
            if(right+ 1 < n/* && nums[right+1] != 0*/) diff[right +1] -= 1;   
        }
        for(int i =1 ;i < n;i++){
            diff[i] += diff[i-1];
            
        }
        for(int i =0 ;i < n;i++){
           if(diff[i] < nums[i] ){
            return false;
           }
            
        }
        return true;
    }
};