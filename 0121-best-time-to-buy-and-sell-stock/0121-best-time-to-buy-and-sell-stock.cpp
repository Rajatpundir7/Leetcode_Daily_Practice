class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int curr = 0; int maxi = 0;
        for(int i =0 ;i < n ; i++ ){
            for(int j = i+1;j<n;j++){
                curr = prices[j] - prices[i];
                maxi = max(curr, maxi);
            }
        }
        return maxi;
        /*
        int minipro= INT_MAX;
        int profit = 0;
        for(int x : prices){
            minipro = min(minipro, x );
            profit =  max(profit ,  x - minipro);
        }
        return profit;*/

        /*
        int mini =0 , miniidx =0 , maxiidx = 0 ,maxi =0;
        for(int i =0; i<n ;i++){
            if(mini > prices[i] ){
                mini = prices[i];
            }

            if(maxi < prices[i]){
                maxi = prices[i];
            }
        }*/
       // return maxi;
    }
};