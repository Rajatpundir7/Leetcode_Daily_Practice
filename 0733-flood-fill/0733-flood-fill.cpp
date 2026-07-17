class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>>vis = image;
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir = { {0,1},{-1,0},{0,-1},{1,0}};
        q.push({sr,sc});
        while(!q.empty()){
            sr = q.front().first;
            sc = q.front().second;
            vis[sr][sc] = color;
            q.pop();
            for(auto it : dir){
                int i = it.first;
                int j = it.second;
                if(sr + i >=0 && sr + i < n && sc + j < m  && sc + j >= 0 && image[sr+i][sc+j] == image[sr][sc] && vis[sr+i][sc + j] != color){
                  //  vis[sr+i][sc+j] = color;
                    q.push({sr+i, sc+j});
                }
            }

        }
        /*for(int i =0 ;i < n ;i++){
            for(int j =0 ;j < m;j++){
                if(image[i])
            }
        }*/
        return vis;
    }
};