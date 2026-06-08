class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        ///int j =0 , i =0 ;
        int minpos =-1;
        int maxpos = -1;
        int culpet = -1;
        long long ans = 0 ;
        for(int i =0 ;i < n;i++){
            if(nums[i] > maxK || nums[i] < minK){
                culpet = i;
            }
            if(nums[i] == maxK){
                maxpos =i;
            }
            if(nums[i] == minK){
                minpos = i;
            }
            long long smallest = min(minpos, maxpos);

            long long temp = smallest -culpet;

            ans += (temp <0 ? 0: temp); 
        }
        return ans ;

    }
};