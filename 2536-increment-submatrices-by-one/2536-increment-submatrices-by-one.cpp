class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>diff(n,vector<int>(n,0));
        int m = queries.size();
        for(int i =0 ; i< m;i++){
            int row1 = queries[i][0];
            int col1 = queries[i][1];
            int row2 = queries[i][2];
            int col2 = queries[i][3];
            /*for(int j = row1;j<= row2;j++){
                for(int k = col1;k<= col2;k++){
                    mat[j][k]++;
                }
            }*/
            for(int j = row1;j<= row2;j++){
                diff[j][col1] += 1;
                if(col2+1 < n) diff[j][col2+1] -= 1;
            }
        

        }

        for(int i =0 ;i < n ;i++){
            for(int j =1 ; j < n;j++){
                diff[i][j] += diff[i][j-1];
            }
        }
        return diff;
    }
};