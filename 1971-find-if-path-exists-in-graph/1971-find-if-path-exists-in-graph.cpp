class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(int i =0 ;i < edges.size();i++){
            int v = edges[i][0];
            int u = edges[i][1];

            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int a = q.front();
            q.pop();
          //  vis[it] = 1;
            if(a == destination){
                        return true;
                    }

            for(auto it : adj[a]){
                if(!vis[it]){
                    vis[it] =1;
                    q.push(it);
                }
            }


        }
        return false;
        
    }
};