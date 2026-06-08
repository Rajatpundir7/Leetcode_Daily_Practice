class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> freq;
        freq[0] = 1; 
        int currsum = 0;
        int ans = 0;

        for(int x : nums){
            currsum += x;
            if(freq.find(currsum - goal) != freq.end()){
                ans += freq[currsum - goal];
            }
            freq[currsum]++;
        }
        return ans;
    }
};
