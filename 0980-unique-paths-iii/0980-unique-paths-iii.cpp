class Solution {
public:
    int uniqpath =0;
     vector<pair<int,int>>dir = {{1,0} , {0,1} , {-1,0} , {0,-1}};

    void countways(int i , int j, vector<vector<int>>&grid , int obs ,int n ,int m ,int ans ){
       if(i <0 || i >= n || j < 0 || j >= m || grid[i][j] == -1  ){
        return ;

       }
       if(grid[i][j] == 2){
        if(ans == obs){
            uniqpath++;
        }
        return ;
       }
       grid[i][j] = -1;

       for(auto it : dir){
        int a = it.first + i;
        int b = it.second + j;
        countways(a,b,grid,obs,n,m,ans+1);
       }

    grid[i][j] =0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int obs =0;
        int startx =0 , starty =0;
        for(int i =0; i<n;i++ ){
            for(int j =0 ; j< m;j++){
                if(grid[i][j] == 0){
                    obs++;
                }
                if(grid[i][j] == 1){
                    startx = i;
                    starty = j;
                }
            }
        }
        int ans =0;

        obs++;
        countways(startx,starty,grid,obs,n,m,ans);

 return uniqpath;
    }
};