class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>large(n);
        vector<int>small(n);
        large[0] = nums[0];
        small[n-1] = nums[n-1];
        int index = 0 ;
        int small_index = 0;
        for(int i =1;i<n;i++ ){
            large[i] = max(large[i-1],nums[i]);
        }
        for(int i = n-2 ;i>= 0;i--){
            small[i] = min(nums[i],small[i+1]);
        }
        for(int i =0 ;i < n;i++){
            int score = large[i] - small[i];
            if(score <= k ) {
                index = i;
                return index;
                //small_index = min(small_index,index);
            }

        
        }
        return -1;

    }
};