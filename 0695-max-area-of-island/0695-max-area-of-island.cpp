class Solution {
public:

    int  bfs(int row , int col , vector<vector<int>>&vis , vector<vector<int>>&grid){
        vector<pair<int,int>>dir = { {0,1},{1,0} ,{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        vis[row][col] =1;
        q.push({row,col});
        int n =  grid.size();
        int m = grid[0].size();
        int area =0;
        while(!q.empty()){
            row = q.front().first;
            col = q.front().second;
            area++;
            q.pop();
        for(auto it : dir){
            int i = it.first;
            int j = it.second;
            if(row + i >= 0 && row+ i < n && col + j >= 0 && col + j < m && vis[row+i][col+j] ==0  && grid[row+i][col+j] == 1){
                q.push({row+i,col+j});
                vis[row+i][col+j] =1;


            }
        }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n = grid.size();
        int m =  grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
    int count =0 ;
        for(int i =0 ;i < n;i++){
            for(int j =0 ; j <m;j++){
                if(vis[i][j]  == 0 &&  grid[i][j] == 1 ){
                   //count.push_back
                  count = max(count,bfs(i,j,vis,grid));
                   // count++;
                }
            }
        }
       /* int ans =0;
        for(int i =0 ; i< count.size();i++){
            if(ans < count[i]){
                ans = count[i];
            }
        }*/
        return count;
    }
};