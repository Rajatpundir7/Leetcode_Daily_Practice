class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums) {
            sum += x;
        }
        vector<int> ans(n);
        int left = 0;
        for(int i = 0; i < n; i++) {
            sum -= nums[i];  
            ans[i] = abs(left - sum);
            left += nums[i];
        }
        return ans;
    }
};