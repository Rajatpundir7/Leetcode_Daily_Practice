class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int  n = nums.size();
        vector<int>ans;
       // unordered_map<int,int>mp;
       // vector<vector<int>>vec;
        for(int i =0 ;i< n;i++){
            int num = nums[i];
           /* if(mp.count(num) ){
                ans.push_back(mp[num]);
                continue;
            }*/
            int flag = 0;
            for(int j = i+1 ;j<n;j++){
                if(num < nums[j]){
                   // mp[num] = nums[j];
                    ans.push_back(nums[j]);
                    flag = 1;
                    break;
                }

            }
            if(flag ==0 ){
            for(int j  = 0 ;j< i;j++){
                 if(num < nums[j]){
                  //  mp[num] = nums[j];
                    ans.push_back(nums[j]);
                    flag = 1;
                    break;
                }
            }
            }

            if(flag == 0){
                ans.push_back(-1);
            }
        }
        return ans ;
    }
};