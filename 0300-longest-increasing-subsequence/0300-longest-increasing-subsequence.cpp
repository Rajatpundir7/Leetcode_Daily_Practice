class Solution {
public:
    void min(int i ,vector<int> &dp , vector<int> &nums){
        for(int j = 0 ;j< i;j++){
            if(nums[i]>nums[j])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        }
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
       vector<int> dp(n,1);
       int ans  =0 ;
       for(int i =0 ;i < n; i++){
       /*{
        if(nums[i] < nums[i+1]){
            dp[i+1] = dp[i]+1;
        }
        else{
            dp[i+1] = max(dp[i+1] , dp[i]);
        }*/
        min(i,dp,nums);
        ans = max(ans,dp[i]);

       }
       return ans;
    }
};