class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        unordered_map<int,int>mp(maxi);
        int n = nums.size();
        for(int i =0 ;i <n;i++){
            if(nums[i] % 2 == 0){
                mp[nums[i]]++;
            }
        }
        for(int i =0 ;i<n;i++){
            if(nums[i] % 2 == 0){
               if(mp[nums[i]] == 1){
                return nums[i];
               }
            }

        }
        return -1;
    }
};