class Solution {
public:
void dfs(int i , int j , vector<vector<int>>&vis, vector<vector<int>>&board , vector<pair<int,int>>&dir,int m , int n){
        
        vis[i][j] =1;
        for(auto it : dir){
            int a  = it.first;
            int b = it.second;

            if(i +a >= 0 && i+a <m && j+b >= 0 && j+b < n && vis[i+a][j+b] == 0 && board[i+a][j+b] == 1){
                dfs(i+a,j+b,vis,board,dir,m,n);
            }
        }
        return ;
    }
    int numEnclaves(vector<vector<int>>& board) {
         int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<pair<int,int>>dir= { {1,0},{0,1},{-1,0} ,{0,-1}};

        for(int i =0 ;i < n; i++){
            if(board[0][i] == 1 && vis[0][i] == 0){
                dfs(0,i,vis,board,dir,m,n);
            }

            if(board[m-1][i] == 1 && vis[m-1][i] == 0){
                dfs(m-1,i,vis,board,dir,m,n);
            }
        }

        for(int i =0 ;i < m; i++){
            if(board[i][0] == 1 && vis[i][0] == 0){
                dfs(i,0,vis,board,dir,m,n);
            }

            if(board[i][n-1] == 1 && vis[i][n-1] == 0){
                dfs(i,n-1,vis,board,dir,m,n);
            }
        }
        int count =0 ;
        for(int i =0 ;i < m; i++){
            for(int j =0 ;j < n; j++){
            if(board[i][j] == 1 && vis[i][j] == 0){
               count++;
            }
        }
        }
        return count;
    }
};