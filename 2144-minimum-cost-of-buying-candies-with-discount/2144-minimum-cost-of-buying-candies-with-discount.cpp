class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int totalcost =0;
        // if(n == 0) return 0;
        // if(n == 1) return cost[0];
        // if(n == 2) return cost[0] + cost[1];
        for(int i = n-1;i>= 0;){
            totalcost += cost[i];
            i--;
            if(i>= 0){
                
            totalcost += cost[i];
            i--;
            }
            if(i>= 0){
                i--;
            
            }
            
        }
        return totalcost;
    }
};