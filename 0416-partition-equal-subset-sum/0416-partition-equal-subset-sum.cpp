class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int num : nums)
            sum += num;
        
        if(sum % 2 != 0)
            return false;
        
        int t = sum / 2;
        
        
        vector<bool> dp(t+ 1, false);
        dp[0] = true;  
        
        for(int num : nums) {
        
            for(int j = t; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[t];
    }
};