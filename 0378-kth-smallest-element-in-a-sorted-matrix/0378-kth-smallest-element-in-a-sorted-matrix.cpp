class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>p;
        int n = matrix.size();
        for(int i =0 ;i < n; i++){
            for(int j =0 ;j < n ; j++){
                p.push({matrix[i][j], {i,j}});
                
            }
        }
        while(k > 1){
            p.pop();
            k--;
        }
        return (p.top().first);
    }
};