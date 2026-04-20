class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(int i =0 ;i <n-1;i++){
            int start  = intervals[i][0];
            int end = intervals[i][1];
            if (end >= intervals[i+1][0]){
                intervals[i+1][0] = start;
                intervals[i+1][1] = max(intervals[i+1][1],end);
                intervals[i][0] = -1;
                intervals[i][1] = -1;

            }
        }

        for(int i =0 ;i < n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start != -1 && end != -1){
                ans.push_back({start,end});
            }
        }
        return ans ;
        
    }
};