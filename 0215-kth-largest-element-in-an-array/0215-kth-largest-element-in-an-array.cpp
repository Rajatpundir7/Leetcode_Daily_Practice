class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>mp;

        for(int x: nums) mp.push(x);

        while(k > 1) {
            mp.pop();
            k--;
        }
        return mp.top();

    }
};