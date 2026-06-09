class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i =0 ; i <n;i++){
            mp[nums[i]]++;
        }
       // int  = 0;
        //int previous = mp[nums[0]];
       // int i =1 ;
        unordered_map<int,int> mp2;
        for(auto &x: mp){
            mp2[x.second]++;
            //i++;
        }

        for(int i =0 ;i < n;i++){
            if(mp2[mp[nums[i]]] == 1){
                return nums[i];
            }
        }
        return -1;
    }
};