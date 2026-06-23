class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        /*int n = nums.size();
        vector<int>prefixsum(n+1,0);
        for(int i = 1  ; i<n+1;i++){
            prefixsum[i] = prefixsum[i-1] + nums[i-1];
        }
        if(n < 2 ) return false;
        if(n == 2){
            return (prefixsum[2]%k == 0);
        }
        for(int i =2 ;i <= n;i++){
            for(int j = 0 ; j <= i-2;j++ ){
                if((prefixsum[i] - prefixsum[j]) %k == 0){
                    return true;
                }
            }
        }
        return false;*/
        int n = nums.size();
        unordered_map<int,int>seen;
        seen[0] = -1;
        int sum =0;
        for(int i =0 ;i < n ;i ++){
            sum += nums[i];
            int rem = sum %k;
            if(seen.count(rem)){
                if(i-seen[rem] >= 2)return true ;
            }
            else{
                seen[rem] = i;
            }
        }
        return false;
    }
};