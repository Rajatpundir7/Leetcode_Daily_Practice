class Solution {
public:
    int bs(vector<int>&nums, int target,int n){
        int low =0 , high = n-1; 
        int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
            
           // if(nums[low] == target){  low = mid -1;}
            // if(nums[high] == target) { high = mid +1;}
            if(nums[mid] == target){
                ans = mid;
                high = mid -1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
     int bs1(vector<int>&nums, int target,int n){
        int low =0 , high = n-1; 
         int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
           
           // if(nums[low] == target){  low = mid -1;}
            //if(nums[high] == target) { high = mid +1;}
            if(nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
       ans.push_back(bs(nums,target,n));
       ans.push_back(bs1(nums,target,n));
       return ans;
    }
};