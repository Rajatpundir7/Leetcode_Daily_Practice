class Solution {
public:
    int bs_upper(vector<int>&nums , int target , int n){
        int low = 0, high = n;
        int mid = 0;
        while(low < high){
            mid = low + (high - low)/2;
            if(nums[mid] <= target){
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    int bs_lower(vector<int>&nums, int target,int n){
        int low = 0 , high =n;
        int mid =0 ;
        while(low < high){
            mid = low + (high - low)/2;
            if(nums[mid] < target ){
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        return low ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lower = bs_lower(nums, target ,n);
        if( lower == n || nums[lower] != target ){
            return {-1,-1};
        }
        int upper = bs_upper(nums,target , n);

        vector<int>ans ;
        ans.push_back(lower);
        ans.push_back(upper-1);
                return ans;
    }
};