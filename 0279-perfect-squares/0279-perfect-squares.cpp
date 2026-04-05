class Solution {
public:
    int numSquares(int n) {
        vector<int> coins;
        for(int i = 1 ; i*i <=n ;i++){
            coins.push_back(i*i);
        }
        vector<int> dp(n+1 , INT_MAX);
        dp[0] = 0;

        for(int coin : coins){
            for(int i = coin ; i<=n;i++){
                if(dp[i-coin] != INT_MAX){
                dp[i] = min(dp[i] ,  dp[i-coin]+1);
                }
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};