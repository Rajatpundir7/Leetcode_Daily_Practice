class Solution {
public:

    bool candivide(vector<int>& nums , int k ,int maxsum , int n){
        int curr =0;
        int parts =0;
        for(int i =0 ;i < n;i++){
            if(curr + nums[i] > maxsum ){
                curr =0;
                parts++;

            }
            curr  += nums[i];
            if(parts > k) return false;
        }
        return parts < k;
    } 
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi =nums[0] ;
        int ans =0 ;
        int total = 0;

        for(int i =0 ;i<n;i++){
            total += nums[i];
            if(nums[i] > maxi) maxi = nums[i];
        }
        int low = maxi , high = total;
        while(low <= high){
            int mid = low + (high -low)/2;

            if(candivide(nums , k , mid , n)){
                ans = mid;
                high = mid -1;

            }
            else{
                low = mid +1;

            }
        }
        return ans ;
    }
};