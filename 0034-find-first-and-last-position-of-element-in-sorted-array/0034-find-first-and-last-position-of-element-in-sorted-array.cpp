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
    int upper_bound(vector<int>&nums,int target , int n){
        int low = 0 , high = n;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] <= target) {
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        int n = nums.size();

        int first = lower_bound(nums,target,n);
        if(first  == n || nums[first] != target){
            return {-1,-1};
            //return ans ;
        }
      // ans.push_back();
      int last = upper_bound(nums,target,n);
       ans.push_back(first);
       ans.push_back(last-1);
       return ans;
    }
};