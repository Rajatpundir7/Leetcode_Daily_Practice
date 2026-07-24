class Solution {
public:
    int backtrack(vector<int>&nums,int xor1,int idx , int n){

        if(idx >= n){
            return xor1;
        }

        int include = backtrack(nums,xor1^nums[idx],idx+1,n);
        int exclude = backtrack(nums,xor1,idx+1,n);
        return include+ exclude;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return backtrack(nums,0,0,n);
    }
};