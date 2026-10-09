class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       /*
        0 - 1 , 2
        1 - 0 ,2 
        2 - 0 , 1
        so , 
        step 1 : we create adgendecy list 
        bidirection graph  u -> v and v -> u
       */
       vector<vector<int>>adj(n);
       for(int i =0 ;i < edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       /*
       try to move / travel from source to destination
       start travelsal from the soures 
       */

       queue<int>q;
       vector<int>vis(n,0);
       q.push(source);
       
       while(!q.empty()){
        int node =  q.front();
        q.pop();
        vis[node] =1;
        if(node == destination){
            return true ;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] =1;
            }
        }
        
       }
        return false;
       
    }
};