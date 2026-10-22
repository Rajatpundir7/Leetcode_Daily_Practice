class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    
        priority_queue<pair<int,int>>q;
        int n = nums.size();
         //int count =0 ;
         unordered_map<int,int>mp;
        for(int i =0 ;i < n; i++){
           mp[nums[i]]++;

        }

        for(auto x: mp){
            q.push({x.second, x.first});

        }
        vector<int>ans;

        while(k > 0){
            ans.push_back(q.top().second);
            k--;
            q.pop();
        }
        return ans;

    }
};