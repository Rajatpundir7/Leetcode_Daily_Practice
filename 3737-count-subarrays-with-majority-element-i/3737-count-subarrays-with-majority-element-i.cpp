class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        //unordered_map<int,int>mp;
        int n = nums.size();
        /*for(int i = 0;i <n;i++){
            mp[nums[i]]++;
        }*/
        vector<int>count(n,0);
        int c = 0;
        for(int i =0 ;i < n;i++){
            if(nums[i] == target){
               count[i] = 1;
            }
            else{
            count[i]= -1;
            }
        }
        vector<int>prefix(n+1,0);
        for(int i =0 ;i < n; i++){
            prefix[i+1] = prefix[i] + count[i];
        }
        int ans =0;
        for(int i  =0 ; i< n;i++){
            for(int j = i+1 ;j <=n;j++){
                if(prefix[j] - prefix[i] > 0)  ans++;
            }
        }
        return ans ;
    }
};