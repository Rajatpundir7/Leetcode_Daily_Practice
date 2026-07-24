class Solution {
public:
    void backtrack(vector<int>&nums, vector<vector<int>>&result, vector<int>&curr , vector<int>&freq, int n){
        if(curr.size() == n){
            result.push_back(curr);
            return;
        }

        for(int i =0 ;i < n;i++){
            if(freq[i] == 0){
                freq[i] =1;
                curr.push_back(nums[i]);
                backtrack(nums,result,curr,freq,n);
                freq[i] = 0;
                curr.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>curr;
        vector<int>freq(n,0);
        backtrack(nums,result,curr,freq,n);
        return result;
    }
};