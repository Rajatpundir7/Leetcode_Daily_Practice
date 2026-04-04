class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1 , 0));
      //  vector<pair<int,int>>p;
        for(string st : strs){
            int currsize = st.length();
            int one = count(st.begin() , st.end() ,'1');
            int zeros = currsize - one;
           // p.push({zeros , one});

           for(int i = m ; i >= zeros ;i -- ){
            for(int j = n ; j >= one ; j--){
                dp[i][j] = max(dp[i][j] , dp[i-zeros][j-one]+1);
            }
           }
        }

        /*for(auto & x: p){

        }*/
        return dp[m][n];
    }
};