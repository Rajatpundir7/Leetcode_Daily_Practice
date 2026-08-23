class Solution {
public:
    int search(vector<int>& nums, int target) {
        // APPROCH --  IN while loop (low < high) 
        // if at mid idx value == target then return mid 
        // else check in left half sorted 
        // right half sorted 

        int n = nums.size();
        int low = 0 , high = n- 1;

        while(low <= high){
            int mid  = low +  (high - low)/2;

            if(nums[mid] == target) return mid;

            // for left sorted 
            if(nums[low] <= nums[mid] ){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid -1;
                }
                else{
                    
                    low = mid +1;
                }
            } // for right sorted 
            else{
                if(nums[mid] < target &&  target <= nums[high]){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};