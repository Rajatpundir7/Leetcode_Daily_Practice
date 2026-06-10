class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        /*int currcount =0;
        int maxcount = 0;
        for(int i =0 ;i < n ;i++){
            if(nums[i] == 1){
                currcount++;
            }
            else{
                maxcount = max(currcount,maxcount);
                currcount
            }
        }*/
        int i =0 , j=0;
        int zeros =0 ;
        int maxones =0;
        while(j < n){
            if(nums[j] == 0 ) zeros++;

            while(zeros > k){
                if(nums[i] == 0 ) zeros--;
                i++;

            }
            maxones = max(maxones, j-i+1);
            j++;

        }
        return maxones;
    }
};