class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

       /* vector<vector<int>>adj(n);

       
        for(int i =0 ;i <n;i++){
            for(auto it : rooms[i]){
                adj
            }
        }*/
         int n = rooms.size();
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        vis[0] =1;
        while(!q.empty()){
            int node = q.front();
            
            q.pop();
            for(auto it : rooms[node]){
                if(!vis[it]){
                    vis[it] =1;
                    q.push(it);
                }
            }

        }
        for(int i =0 ;i < n;i++){
            if(vis[i] ==0){
               // cout<<vis[i];
                return false;
            }
        }
        return true;
    }
};