class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*priority_queue<int> pq;
        for(int num : stones) pq.push(num);

        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x != y){
                pq.push(x-y);
            }
        }
        return pq.top();*/

        // do subset me divide karna and minimise diffrence 
/*
        int sum = accumulate(stones.begin() , stones.end() , 0);

        int half = sum /2;

        //priority_queue<int> pq;

        sort(stones.begin() , stones.end());

        int temp = 0;
        int n = stones.size();
        vector<int>diff;
        for(int i = n-1; i> n/2; i-- ){
            temp  += stones[i];
            diff.push_back(temp - half);
        }
        int ans = abs(diff[0]);
        for(int i =0 ;i <diff.size() ; i++){
            ans = min(ans , abs(diff[i]));
        }
return ans ;*/
int sum  = accumulate(stones.begin() , stones.end() , 0);
int goal = sum / 2 ;

vector<bool> dp(goal+1,0);
dp[0] = true;
for(int num : stones){
    for(int j = goal ; j >= num; j--){
        dp[j] = dp[j] || dp[j- num];
    }
}
for(int i = goal; i >= 0 ; i--){
    if(dp[i]){
        return sum - 2* i;
    }
}
return 0;
    }
};