class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
         
        int n = stones.size();

        for(int i =0 ; i< n;i++){
            q.push(stones[i]);
        }
        while(q.size() > 1){
            int stone1 =  q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();
            int diff = (stone1- stone2);
            if(diff == 0) {
                continue;
            }
            else{
                q.push(diff);
            }
        }
        if(q.empty()) return 0;
        return q.top();
    }
};