class Solution {
public:

    class cmp{
        public:
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            if(a.first == b.first) {
                return a.second >    b.second;
            }
            return a.first < b.first ;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string , int>mp;
        
        for(int i =0 ; i< n ;i++){
            mp[words[i]]++;
        }
        
        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            cmp
        > p;
        for( auto x : mp){
            p.push({x.second,x.first});
        }
        vector<string>ans;
        while(k--){
           ans.push_back(p.top().second);
           p.pop(); 
        }
        return  ans ;
    }
};