class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int,int>> q;

        // Push all 0s into the queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        // Directions
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // BFS from all 0s
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(auto it : dir){
                int a = it.first;
                int b = it.second;
                int ni = i + a;
                int nj = j + b;

                if(ni >= 0 && ni < n && nj >= 0 && nj < m && ans[ni][nj] == -1){
                    ans[ni][nj] = ans[i][j] + 1;
                    q.push({ni,nj});
                }
            }
        }

        return ans;
    }
};
