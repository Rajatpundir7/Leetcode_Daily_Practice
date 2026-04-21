class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int k =1 ;
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(k+1,INT_MIN));
        dp[0][0] = arr[0];
        int ans = arr[0] ;
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= k; j++){
                if(dp[i-1][j] != INT_MIN){
                    dp[i][j] = max(dp[i-1][j] + arr[i] , dp[i][j]);
                }

                if(j > 0 && dp[i-1][j-1] != INT_MIN){
                    dp[i][j] = max(dp[i][j] , dp[i-1][j-1]);
                }

                //dp[i][j] = max(dp[i][j] , (j == 0) ? arr[i] :INT_MIN);

                if (j == 0)                       
                    dp[i][j] = max(dp[i][j], arr[i]);

                if (dp[i][j] != INT_MIN)
                    ans = max(ans, dp[i][j]);
            }
        }
        return ans ;
    }
};