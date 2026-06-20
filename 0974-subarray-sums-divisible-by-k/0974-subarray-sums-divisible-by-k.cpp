class Solution {
public:

    int subarraysDivByK(vector<int>& nums, int k) {
        int n  = nums.size();
        int sum = 0;
        int ans  =0 ;
        // vector<int> prefixsum(n+1,0);
        // for(int i =0 ;i < n ;i++){
        //     prefixsum[i+1] = prefixsum[i] + nums[i];
        // }

        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int i =0  ; i < n  ; i++){
            sum += nums[i];
            int rem = sum% k;
            if(rem < 0){
                 rem += k;
            }
            if(mp[rem] > 0){
                ans += mp[rem];
                mp[rem]++;
            }
            else{
                mp[rem]++;
            }
        }
        return ans;
    }
};