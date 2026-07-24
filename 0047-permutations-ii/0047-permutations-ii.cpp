class Solution {
public:
void backtrack(vector<int>&nums, vector<vector<int>>&result, vector<int>&curr , unordered_map<int,int>&freq, int n){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(auto it : freq){
            int val = it.first;
            int count = it.second ;
            if(count > 0){
                freq[val]--;
                curr.push_back(val);
                backtrack(nums,result,curr,freq,n);
                freq[val]++;
                curr.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>curr;
        unordered_map<int,int>freq;
        for(int it : nums){
            freq[it]++;
        }
        backtrack(nums,result,curr,freq,n);
        return result;
    }
};