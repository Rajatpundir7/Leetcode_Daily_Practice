class Solution {
public:
    int uniquePaths(int m, int n) {
    /* long long a = 1;
     long long  b = 1;
     long long  c =1;
     for(int i = 2 ;i < n ;i++){
        b *=  i;
     }
     for(int i = 2 ; i < m ;i++){
        c *= i;
     }
     for(int i = 2 ;i <m + n -1;i++){
        a *= i;
     }
     return (int)(a/(b*c));*/
// aproch fing  the combination      
// 
/*
     int total = (m - 1 + n -1);
     long long  ans  =1 ;
     int r = min(n-1, m -1 );
     for(int i = 1 ;i <= r ;i++){
        ans = ans * ( total - r + i)/ i;
     }
     return (int)ans;*/

     vector<vector<int>> dp(m, vector<int>(n,1));

     for(int i = 1 ; i < m; i++){
        for(int j = 1; j< n;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
     }
     return dp[m-1][n-1];
    }

};