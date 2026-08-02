class Solution {
public:
int lower_bound(vector<int>&nums,int target , int n){
        int low = 0 , high = n;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target) {
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums,target,nums.size());
    }
};