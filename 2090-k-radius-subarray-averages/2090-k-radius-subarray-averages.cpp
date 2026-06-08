class Solution {
public:
    int getavg(vector<long long>&prefixsum,int i , int k){
        long long sum =prefixsum[i+k+1] - prefixsum[i-k];
        
        return (int)(sum/((2*k) + 1));
    }
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        if(n < 2*k +1){
            for(int i =0 ;i < n;i++){
            ans.push_back(-1);
            }
            return ans;
        }
        vector<long long>prefixsum(n+1,0);
       for(int i =0 ; i<n;i++){
            prefixsum[i+1] = prefixsum[i] + nums[i];
       }
        for(int i =0 ;i < k;i++){
            ans.push_back(-1);
        }
        
        for(int i = k ;i<= n-k-1;i++){
            ans.push_back(getavg(prefixsum,i,k));
        }

        for(int i = n-k;i<n;i++){
            ans.push_back(-1);
        }
        return ans;
    }
};