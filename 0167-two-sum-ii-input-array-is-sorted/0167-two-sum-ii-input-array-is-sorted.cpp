class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int high =  n-1 , low = 0;
        while(low < high){
            int sum  = nums[high] + nums[low];
            if(sum == target) return {low+1,high+1};
            else if(sum < target) low++;
            else high--;
        }
        return {-1,-1};
    }
};