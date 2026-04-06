class Solution {
public:

int lcs(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1 , vector<int>(m+1,0));

        for(int i = 1;i<= n;i++){
            for(int j =1 ; j<= m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {

        if(word1 == word2){
            return 0;
        }
        else {
        //return lcs(word1,word2);
        int n = word1.size();
        int m = word2.size();
       /* for(char ch : word1)
        }*/
        return m+n-(2*lcs(word1,word2));
        }
    }
};