class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i =0  , j= 0;
        int minlen = n+2;
        int sum =0;
        while(j < n){
            sum += nums[j];

            while(sum >= target){
                minlen = min(minlen , j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minlen == n+2 ? 0 : minlen;
    }
};