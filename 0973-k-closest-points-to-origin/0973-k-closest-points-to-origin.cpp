class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<double , pair<int,int>>>p;
        for(int i =0 ;i < n ; i++ ){
            int x = points[i][0];
            int y = points[i][1];
            double dis = sqrt((x*x) + (y*y));
            p.push({dis,{x,y}});
        }
        vector<vector<int>>ans;
        int count = n-k;
        while(count > 0){
            p.pop();
            count--;

        }
        while(k){
            ans.push_back({p.top().second.first,p.top().second.second});
            p.pop();
            k--;
        }
        return ans ;
    }
};