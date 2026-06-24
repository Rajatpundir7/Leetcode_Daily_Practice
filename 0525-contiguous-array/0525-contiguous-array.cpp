class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1; 
        int prefix_sum = 0, max_len = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefix_sum += (nums[i] == 1 ? 1 : -1);

            if(mp.find(prefix_sum) != mp.end()) {
                max_len = max(max_len, i - mp[prefix_sum]);
            } else {
                mp[prefix_sum] = i;
            }
        }
        return max_len;
    }
};
