class Solution {
public:
    void backtrack(vector<int>&nums,vector<vector<int>>&result,vector<int>&curr,int m,int idx){
        if(idx >= m ){
            result.push_back(curr);
            return;
        }
        unordered_set<int>st;
       // for(int i =idx;i<m;i++){
           // if(curr.empty() && (st.find(nums[i]) == st.end())){
                curr.push_back(nums[idx]);
                backtrack(nums,result,curr,m,idx+1);
                curr.pop_back();
                backtrack(nums,result,curr,m,idx+1);
           // }
      //  }


    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>result;
        vector<int>curr;
       // result.push_back(curr);
        backtrack(nums,result,curr,n,0);
        return result;

    }
};