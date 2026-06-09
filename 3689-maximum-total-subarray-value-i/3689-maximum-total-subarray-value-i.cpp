class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n  = nums.size();
        int minN = *min_element(nums.begin(),nums.end());
        int maxN = *max_element(nums.begin(),nums.end());

        return 1LL *(maxN- minN) * k;
    }
};