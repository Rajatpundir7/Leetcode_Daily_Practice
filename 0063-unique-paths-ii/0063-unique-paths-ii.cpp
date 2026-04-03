class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstaclegrid) {
        int  n = obstaclegrid.size();
        int m = obstaclegrid[0].size();

        if (obstaclegrid[0][0] == 1 || obstaclegrid[n-1][m-1] == 1) return 0;
        obstaclegrid[0][0] = 1;
        for(int i = 1 ;i < m ;i++){
            if(obstaclegrid[0][i] == 0 && obstaclegrid[0][i-1] == 1){
                obstaclegrid[0][i] = 1;
            }
            else{
                obstaclegrid[0][i] = 0;
            }
        }
        for(int i = 1 ;i < n ;i++){
            if(obstaclegrid[i][0] == 0 && obstaclegrid[i-1][0] == 1){
                obstaclegrid[i][0] = 1;
            }
            else{
                obstaclegrid[i][0] = 0;
            }
        }
        for(int i = 1;i<n;i++){
            for(int j  = 1 ;j < m;j++){
                if(obstaclegrid[i][j] == 0){
                obstaclegrid[i][j] = obstaclegrid[i][j-1] + obstaclegrid[i-1][j];

            }
            else{
                obstaclegrid[i][j] = 0;
            }
            }
        }
        return obstaclegrid[n-1][m-1];
    }
};