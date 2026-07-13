class Solution {
public:

    /*void dfs(int node , vector<int> &vis, vector<int>adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }*/
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n = isConnected.size();

        vector<int> adj[n+1];
        for(int i =0 ;i < n;i++){
            for(int j =0 ; j < n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int count =0 ;

        vector<int>vis(n+1,0);
       /* for(int i =1 ;i <= n;i++){
            //int node =  
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }*/
       // queue<int> q;
        for(int i = 1; i <= n ;i++){
            if(!vis[i]){
            //int node = i ;

            queue<int>q;
           q.push(i);
           count++;
          vis[i] =1;
        
          q.push(1);
            while(q.size() != 0){
                int node = q.front();
                //count++;
               // vis[node] =1;
                q.pop();
                for(auto it : adj[node]){
                    if(!vis[it]){
                        vis[it] =1;
                        q.push(it);
                    }
                }
            }
            }
        }
        
        return count;
    }
};