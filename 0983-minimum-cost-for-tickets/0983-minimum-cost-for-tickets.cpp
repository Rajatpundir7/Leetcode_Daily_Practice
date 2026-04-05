class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        vector<int>dp(days[n-1]+1,0);
       // vector<int>dp(365,INT_MAX);
       unordered_set<int> travel(days.begin(), days.end());


    int l = days[n-1];

   /* for(int i =1 ;i <30;i++){
        if()
    }*/
        for(int i =1 ;i <= l; i++){
             if(travel.find(i) == travel.end()) {
                dp[i] = dp[i - 1]; 
                continue;
             }
            int buy1 =  cost[0];
            int buy7 = cost[1];
            int buy30 = cost[2];

            buy1 += dp[i-1];
            buy7 += dp[max(0,i-7)];
            buy30 += dp[max(0,i-30)];

            dp[i] = min({buy1 , buy7 , buy30});
        }
        return dp[l];
    }
};