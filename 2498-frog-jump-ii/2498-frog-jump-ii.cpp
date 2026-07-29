class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        if (n == 2) {
            return stones[1] - stones[0];
        }
        int ans = stones[1] - stones[0];
        vector<int>dp(n+1,0);
        dp[2] = ans;
        for (int i = 2; i < n; ++i) {
           // dp[i+1] = max(dp[i], stones[i] - stones[i - 2]);
           ans = max(ans,stones[i] - stones[i-2]);
        }

       // return dp[n-1];
       return ans;
    }
};