class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        //cout<< sum;

        if(abs(target) > sum) return 0;
        if((target + sum ) % 2 != 0) return 0;

        int goal = ( sum + target) /2 ;

        vector<int> dp (goal+1,0);
        dp[0] = 1;

        for(int num : nums){
            for(int i = goal ; i >= num ;i--){
                dp[i] += dp[i-num];
            }
        }
        return dp[goal];
    }
};